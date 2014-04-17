<?php

function form_fun_tree(&$form_state) {
  $form = array();

  $form['#tree'] = TRUE;

  $form['home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Home address'),
  );
  $form['home']['street'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address'),
  );
  $form['home']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
  );

  $form['work'] = array(
    '#type' => 'fieldset',
    '#title' => t('Work address'),
  );
  $form['work']['street'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address'),
  );
  $form['work']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function form_fun_tree_submit(&$form, &$form_state) {
  dsm($form_state);
}



