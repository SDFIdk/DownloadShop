core = 7.x
api = 2

; Modules

;hide_submit
projects[hide_submit][subdir] = "contrib"
projects[hide_submit][version] = "2.0"
projects[hide_submit][type] = "module"

;admin_views -- patched
projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.0"
projects[admin_views][patch][] = "http://drupal.org/files/issues/admin_views-enable-use-of-custom-views-2145183-1.patch"
projects[admin_views][type] = "module"

;views -- patched
projects[views][subdir] = "contrib"
projects[views][version] = "3.5"
projects[views][patch][] = "http://drupal.org/files/views_1055616_81_cache.patch"
projects[views][type] = "module"

;ctools patch
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.2"
projects[ctools][patch][] = "https://www.drupal.org/files/1739718-fix-block-warning.patch"
projects[ctools][type] = "module"

;config pages
projects[config_pages][subdir] = "contrib"
projects[config_pages][version] = "1.8"
projects[config_pages][type] = "module"

;filefield_paths
projects[filefield_paths][type] = 'module'
projects[filefield_paths][subdir] = 'contrib'
projects[filefield_paths][download][branch] = '7.x-1.x'
projects[filefield_paths][download][type] = 'git'
projects[filefield_paths][download][url] = 'http://git.drupal.org/project/filefield_paths.git'
projects[filefield_paths][download][revision] = '8b39e7369bdc8790d4075a1a0e7544fb60111eea'

;hierarchical_select
projects[hierarchical_select][type] = 'module'
projects[hierarchical_select][subdir] = 'contrib'
projects[hierarchical_select][download][branch] = '7.x-3.x'
projects[hierarchical_select][download][type] = 'git'
projects[hierarchical_select][download][url] = 'http://git.drupal.org/project/hierarchical_select.git'
projects[hierarchical_select][download][revision] = 'b3e34d9c2a0493108481b78ea5ad75c432a1318d'

;colorbox
projects[colorbox][subdir] = "contrib"
projects[colorbox][version] = "2.8"
projects[colorbox][type] = "module"

;colorbox_node
projects[colorbox_node][type] = 'module'
projects[colorbox_node][subdir] = 'contrib'
projects[colorbox_node][download][branch] = '7.x-3.x'
projects[colorbox_node][download][type] = 'git'
projects[colorbox_node][download][url] = 'http://git.drupal.org/project/colorbox_node.git'
projects[colorbox_node][download][revision] = '898ec235c3d7fa43e8fb74edee2336dcbcba0957'

;subuser
projects[subuser][subdir] = "contrib"
projects[subuser][version] = "2.0-alpha3"
projects[subuser][type] = "module"

;addressfield
projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.2"
projects[addressfield][type] = "module"

;admin_menu
projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc3"
projects[admin_menu][type] = "module"

;background_process
projects[background_process][subdir] = "contrib"
projects[background_process][version] = "1.14"
projects[background_process][type] = "module"

;beautytips
projects[beautytips][subdir] = "contrib"
projects[beautytips][version] = "2.0-beta2"
projects[beautytips][type] = "module"

;better_exposed_filters
projects[better_exposed_filters][subdir] = "contrib"
projects[better_exposed_filters][version] = "3.0-beta3"
projects[better_exposed_filters][type] = "module"

;boolean
projects[boolean][subdir] = "contrib"
projects[boolean][version] = "1.0"
projects[boolean][type] = "module"

;commerce
projects[commerce][subdir] = "contrib"
projects[commerce][version] = "1.4"
projects[commerce][type] = "module"
projects[commerce][patch][] = 'https://www.drupal.org/files/issues/2044231.checkout_order_created_date_update.patch'

;commerce_autosku
projects[commerce_autosku][subdir] = "contrib"
projects[commerce_autosku][version] = "1.1"
projects[commerce_autosku][type] = "module"

;commerce_extra
projects[commerce_extra][subdir] = "contrib"
projects[commerce_extra][version] = "1.0-alpha1"
projects[commerce_extra][type] = "module"

;commerce_features
projects[commerce_features][subdir] = "contrib"
projects[commerce_features][version] = "1.0-rc1"
projects[commerce_features][type] = "module"

;commerce_file
projects[commerce_file][subdir] = "contrib"
projects[commerce_file][version] = "1.0-beta4"
projects[commerce_file][type] = "module"

;commerce_vbo_views
projects[commerce_vbo_views][subdir] = "contrib"
projects[commerce_vbo_views][version] = "1.2"
projects[commerce_vbo_views][type] = "module"

;content_access
projects[content_access][subdir] = "contrib"
projects[content_access][version] = "1.2-beta2"
projects[content_access][type] = "module"

;ctools
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.2"
projects[ctools][type] = "module"

;date
projects[date][subdir] = "contrib"
projects[date][version] = "2.6"
projects[date][type] = "module"

;devel
projects[devel][subdir] = "contrib"
projects[devel][version] = "1.3"
projects[devel][type] = "module"

;diff
projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"
projects[diff][type] = "module"

;email
projects[email][subdir] = "contrib"
projects[email][version] = "1.2"
projects[email][type] = "module"

;entity
projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-rc3"
projects[entity][type] = "module"

;entityreference
projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0"
projects[entityreference][type] = "module"

;features
projects[features][subdir] = "contrib"
projects[features][version] = "1.0"
projects[features][type] = "module"

;field_group
projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"
projects[field_group][type] = "module"

;field_permissions
projects[field_permissions][subdir] = "contrib"
projects[field_permissions][version] = "1.0-beta2"
projects[field_permissions][type] = "module"

;filefield_sources
projects[filefield_sources][subdir] = "contrib"
projects[filefield_sources][version] = "1.7"
projects[filefield_sources][type] = "module"

;google_analytics
projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "1.2"
projects[google_analytics][type] = "module"

;honeypot
projects[honeypot][subdir] = "contrib"
projects[honeypot][version] = "1.13"
projects[honeypot][type] = "module"

;imce
projects[imce][subdir] = "contrib"
projects[imce][version] = "1.5"
projects[imce][type] = "module"

;imce_mkdir
projects[imce_mkdir][subdir] = "contrib"
projects[imce_mkdir][version] = "1.0"
projects[imce_mkdir][type] = "module"

;imce_wysiwyg
projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "1.0"
projects[imce_wysiwyg][type] = "module"

;libraries
projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.0"
projects[libraries][type] = "module"

;link
projects[link][subdir] = "contrib"
projects[link][version] = "1.0"
projects[link][type] = "module"

;masquerade
projects[masquerade][subdir] = "contrib"
projects[masquerade][version] = "1.0-rc5"
projects[masquerade][type] = "module"

;menu_block
projects[menu_block][subdir] = "contrib"
projects[menu_block][version] = "2.3"
projects[menu_block][type] = "module"

;menu_per_role
projects[menu_per_role][subdir] = "contrib"
projects[menu_per_role][version] = "1.x-dev"
projects[menu_per_role][type] = "module"

;menu_position
projects[menu_position][subdir] = "contrib"
projects[menu_position][version] = "1.1"
projects[menu_position][type] = "module"

;metatag
projects[metatag][subdir] = "contrib"
projects[metatag][version] = "1.0-beta2"
projects[metatag][type] = "module"

;migrate
projects[migrate][subdir] = "contrib"
projects[migrate][version] = "2.4"
projects[migrate][type] = "module"

;references
projects[references][subdir] = "contrib"
projects[references][version] = "2.0"
projects[references][type] = "module"

;panels
projects[panels][subdir] = "contrib"
projects[panels][version] = "3.3"
projects[panels][type] = "module"

;pathauto
projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"
projects[pathauto][type] = "module"

;pm_existing_pages
projects[pm_existing_pages][subdir] = "contrib"
projects[pm_existing_pages][version] = "1.4"
projects[pm_existing_pages][type] = "module"

;progress
projects[progress][subdir] = "contrib"
projects[progress][version] = "1.4"
projects[progress][type] = "module"

;querypath
projects[querypath][subdir] = "contrib"
projects[querypath][version] = "2.1"
projects[querypath][type] = "module"

;relation
projects[relation][subdir] = "contrib"
projects[relation][version] = "1.0-rc4"
projects[relation][type] = "module"

;rules
projects[rules][subdir] = "contrib"
projects[rules][version] = "2.2"
projects[rules][type] = "module"

;sharedemail
projects[sharedemail][subdir] = "contrib"
projects[sharedemail][version] = "1.x-dev"
projects[sharedemail][type] = "module"

;simplehtmldom
projects[simplehtmldom][subdir] = "contrib"
projects[simplehtmldom][version] = "1.12"
projects[simplehtmldom][type] = "module"

;smtp
projects[smtp][subdir] = "contrib"
projects[smtp][version] = "1.0-beta2"
projects[smtp][type] = "module"

;strongarm
projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"
projects[strongarm][type] = "module"

;taxonomy_csv
projects[taxonomy_csv][subdir] = "contrib"
projects[taxonomy_csv][version] = "5.10"
projects[taxonomy_csv][type] = "module"

;themekey
projects[themekey][subdir] = "contrib"
projects[themekey][version] = "2.3"
projects[themekey][type] = "module"

;token
projects[token][subdir] = "contrib"
projects[token][version] = "1.4"
projects[token][type] = "module"

;ultimate_cron
projects[ultimate_cron][subdir] = "contrib"
projects[ultimate_cron][version] = "1.9"
projects[ultimate_cron][type] = "module"

;views_bulk_operations
projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.0"
projects[views_bulk_operations][type] = "module"

;views_data_export
projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.0-beta6"
projects[views_data_export][type] = "module"

;wysiwyg
projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.2"
projects[wysiwyg][type] = "module"

;xmlsitemap
projects[xmlsitemap][subdir] = "contrib"
projects[xmlsitemap][version] = "2.0-rc1"
projects[xmlsitemap][type] = "module"

;dbtng_migrator
projects[dbtng_migrator][subdir] = "contrib"
projects[dbtng_migrator][version] = "1.4"
projects[dbtng_migrator][type] = "module"

; _adapt
projects[adapt_module][type] = 'module'
projects[adapt_module][download][type] = 'svn'
projects[adapt_module][download][url] = 'svn+ssh://svnhost/data/subversion/drupal/global/tags/modules/_adapt-7.x-0.4'
projects[adapt_module][directory_name] = "_adapt"
projects[adapt_module][subdir] = "global"

; Libraries
;; Ckeditor
libraries[ckeditor][download][type] = 'svn'
libraries[ckeditor][download][url] = 'svn+ssh://svnhost/data/subversion/drupal/global/tags/libraries/ckeditor-3.6.4'

;; Colorbox
libraries[colorbox][download][type] = 'git'
libraries[colorbox][download][url] = 'git://github.com/jackmoore/colorbox.git'
libraries[colorbox][download][tag] =  1.5.14

; Beautytips
libraries[beautytips_ie_lib][download][type] = "get"
libraries[beautytips_ie_lib][download][url] = "https://cdn.jsdelivr.net/excanvas/r3/excanvas.js"
libraries[beautytips_ie_lib][download][md5] = "d6daf9202fd54f3df4e95369715a4eab"
libraries[beautytips_ie_lib][directory_name] = "excanvas_r3"
libraries[beautytips_ie_lib][destination] = "modules/contrib/beautytips/other_libs"

; Themes
projects[adapt_theme][download][type] = "svn"
projects[adapt_theme][download][url] = "svn+ssh://svnhost/data/subversion/drupal/global/tags/themes/adapt-7.x-0.2"
projects[adapt_theme][directory_name] = "adapt"
projects[adapt_theme][type] = "theme"
projects[adapt_theme][subdir] = "global"


;Remove after live
projects[node_export][subdir] = "contrib"
projects[node_export][version] = "3.0"
projects[node_export][type] = "module"

projects[uuid][subdir] = "contrib"
projects[uuid][version] = "1.0-alpha5"
projects[uuid][type] = "module"

; shared accounts
projects[sharedaccounts][type] = 'module'
projects[sharedaccounts][subdir] = 'custom'
projects[sharedaccounts][download][type] = 'git'
projects[sharedaccounts][download][url] = 'git@github.com:adaptdk/sharedaccounts.git'
projects[sharedaccounts][download][branch] = '7.x-2.x'

;taxonomy_manager
projects[taxonomy_manager][subdir] = "contrib"
projects[taxonomy_manager][version] = "1.0"
projects[taxonomy_manager][type] = "module"

; mailchimp
projects[mailchimp][subdir] = "contrib"
projects[mailchimp][version] = "3.6"
projects[mailchimp][type] = "module"

; MailChimp library
libraries[mailchimp][download][type] = "get"
libraries[mailchimp][download][url] = "https://bitbucket.org/mailchimp/mailchimp-api-php/get/2.0.6.zip"
libraries[mailchimp][directory_name] = "mailchimp"
libraries[mailchimp][destination] = "libraries"
