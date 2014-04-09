/**
* CLEANUP.
*/
DROP TYPE IF EXISTS service CASCADE;
DROP TABLE IF EXISTS smgroup;
DROP TABLE IF EXISTS smusergroup;
DROP VIEW IF EXISTS smusergroup;
DROP VIEW IF EXISTS smuser;
DROP VIEW IF EXISTS smuser_extra;

/**
* SERVICES: TYPE FUNCTION AND VIEW.
*/
CREATE TYPE service AS (
  uid BIGINT,
  userid varchar(255),
  serviceid INT
);
-- Service data function.
CREATE OR REPLACE FUNCTION service_data(service_types TEXT[]) RETURNS SETOF service AS $$
DECLARE
  t TEXT;
BEGIN
  FOREACH t IN ARRAY service_types LOOP
    RETURN QUERY
      EXECUTE format('(
        SELECT
        u.uid,
        CASE
            WHEN ku.field_kms_user_id_value IS NULL THEN u.uid::character varying(255)
            ELSE ku.field_kms_user_id_value
        END AS userid,
        sep_service.field_bundle_webservices_%I_value::int AS serviceid
        FROM users u
        LEFT JOIN field_data_field_kms_user_id ku ON ku.entity_id = u.uid
        JOIN field_data_field_bundle_webservices_%I sep_service ON u.uid = sep_service.entity_id AND sep_service.bundle = ''user''
      )
      UNION ALL (
        SELECT
        u.uid,
         CASE
            WHEN ku.field_kms_user_id_value IS NULL THEN u.uid::character varying(255)
            ELSE ku.field_kms_user_id_value
        END AS userid,
        b_service.field_bundle_webservices_%I_value::int AS serviceid
        FROM users u
        LEFT JOIN field_data_field_kms_user_id ku ON ku.entity_id = u.uid
        JOIN field_data_field_access_bundles b ON u.uid = b.entity_id AND b.entity_type = ''user''
        JOIN field_data_field_bundle_webservices_%I b_service ON b_service.entity_id = b.field_access_bundles_nid AND b_service.bundle = ''access_bundle''
      )', t, t, t, t);


  END loop;
END;
$$ LANGUAGE plpgsql;
-- Service view.
CREATE VIEW userrestrictions2 AS
  SELECT * FROM service_data(array['geo', 'plot', 'wcs', 'wfs', 'wms', 'wmts'])
;
/**
* APPLICATIONS: VIEW.
*/
CREATE VIEW smusergroup AS
  (
    SELECT
      u.uid AS id,
      CASE
        WHEN ku.field_kms_user_id_value IS NULL THEN u.uid::character varying(255)
        ELSE ku.field_kms_user_id_value
      END AS userid,
      a.field_applications_value AS groupid
    FROM users u
      LEFT JOIN field_data_field_kms_user_id ku ON ku.entity_id = u.uid
      JOIN field_data_field_applications a ON u.uid = a.entity_id AND a.bundle = 'user'
  )
  UNION ALL (
    SELECT
      u.uid AS id,
      CASE
        WHEN ku.field_kms_user_id_value IS NULL THEN u.uid::character varying(255)
        ELSE ku.field_kms_user_id_value
      END AS userid,
      a.field_applications_value AS groupid
    FROM users u
      LEFT JOIN field_data_field_kms_user_id ku ON ku.entity_id = u.uid
      JOIN field_data_field_access_bundles b ON u.uid = b.entity_id AND b.entity_type = 'user'
      JOIN field_data_field_applications a ON a.entity_id = b.field_access_bundles_nid AND a.bundle = 'access_bundle'
  )
;
/**
* USER VIEWS.
*/
-- smuser view.
CREATE VIEW smuser AS
  SELECT
    DISTINCT u.uid,
    CASE
      WHEN fdf_kui.field_kms_user_id_value IS NULL THEN u.uid::character varying(32)
      ELSE fdf_kui.field_kms_user_id_value
    END AS userid, u.name, fdf_pc.field_pass_clear_value AS password, fdf_a.field_address_last_name AS lastname, fdf_a.field_address_first_name AS firstname, u.mail AS emailaddress, fdf_p.field_phone_value AS telephonenumber,
    CASE
      WHEN u.status = 1 THEN 0
      WHEN u.status = 0 THEN 1
      ELSE NULL::integer
    END AS disabled,
    fdf_dn.field_debtor_nr_value AS debitorno
  FROM users u
    LEFT JOIN field_data_field_pass_clear fdf_pc ON fdf_pc.entity_id = u.uid
    LEFT JOIN field_data_field_address fdf_a ON fdf_a.entity_id = u.uid
    LEFT JOIN field_data_field_phone fdf_p ON fdf_p.entity_id = u.uid
    LEFT JOIN field_data_field_debtor_nr fdf_dn ON fdf_dn.entity_id = u.uid
    LEFT JOIN field_data_field_kms_user_id fdf_kui ON fdf_kui.entity_id = u.uid
;
-- smuser_extra view.
CREATE VIEW smuser_extra AS
SELECT
  DISTINCT u.uid,
  CASE
  WHEN fdf_kui.field_kms_user_id_value IS NULL THEN u.uid::character varying(32)
  ELSE fdf_kui.field_kms_user_id_value
  END AS userid,
  (SELECT max(field_data_field_user_type.field_user_type_tid) AS max
    FROM field_data_field_user_type
    WHERE field_data_field_user_type.entity_id = u.uid
    GROUP BY field_data_field_user_type.entity_id
  ) AS usertype,
  fdf_uti.field_user_type_info_value AS usertype_info,
  fdf_n.field_newsletter_value AS receive_newsletter,
  fdf_tac.field_terms_and_conditions_value AS accept_terms,
  fdf_cm.field_contact_me_value AS contact_me
FROM users u
  LEFT JOIN field_data_field_user_type fdf_ut ON fdf_ut.entity_id = u.uid
  LEFT JOIN field_data_field_user_type_info fdf_uti ON fdf_uti.entity_id = u.uid
  LEFT JOIN field_data_field_newsletter fdf_n ON fdf_n.entity_id = u.uid
  LEFT JOIN field_data_field_terms_and_conditions fdf_tac ON fdf_tac.entity_id = u.uid
  LEFT JOIN field_data_field_contact_me fdf_cm ON fdf_cm.entity_id = u.uid
  LEFT JOIN field_data_field_kms_user_id fdf_kui ON fdf_kui.entity_id = u.uid
;
