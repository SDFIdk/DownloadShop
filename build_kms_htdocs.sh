#!/bin/bash

PROJECT="kms.dev"
SETTINGS_FILE="mikkel.settings.php"
REPO="svn+ssh://svnhost/data/subversion/drupal/kms/branches/GST-59/htdocs"

BASE_PATH=$(echo `pwd`);

TMP_ID=$(echo `date +%s`)
TMP_DIR="/tmp/${PROJECT}_${TMP_ID}"
TMP_SVN_DIR="${TMP_DIR}/svn"
TMP_MAKE_DIR="${TMP_DIR}/make"

HTDOCS="${TMP_SVN_DIR}/htdocs"
SITES_DEFAULT="${HTDOCS}/sites/default"
PROFILE="${HTDOCS}/profiles/kms"

svn co $REPO $HTDOCS
rm "${SITES_DEFAULT}/settings.php"
cd $SITES_DEFAULT && ln -s $SETTINGS_FILE settings.php

drush make "${PROFILE}/kms.start.make" $TMP_MAKE_DIR

rm -rf "${BASE_PATH}/htdocs" 2>/dev/null
mkdir -p "${BASE_PATH}/htdocs" \
&& cp -rp "${TMP_MAKE_DIR}/." "${BASE_PATH}/htdocs/" \
&& cp -rp "${HTDOCS}/." "${BASE_PATH}/htdocs/" \
&& rm -rf $YMP_DIR \
&& echo -e "\nDone building ${PROJECT} htdocs...\n"

