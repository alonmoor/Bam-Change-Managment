<?php
/**
 * This plugin array is more or less self documenting
 */
$plugin = array(
  // the title in the admin
  'title' => t('Ghetto Twitter pane'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Ghetto Twitter'), -9),
  'edit form' => 'gtwitpane_pane_content_type_edit_form',
  'render callback' => 'gtwitpane_pane_content_type_render'
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function gtwitpane_pane_content_type_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here. 
  // that private js function is so bad that fixing it will be the 
  // basis of the next tutorial
  $block->content = _gtwit_ghetto_js_that_is_bad($conf['twitter_username']);
  return $block;
}


/**
 * 'Edit form' callback for the content type.
 */
function gtwitpane_pane_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  $form['twitter_username'] = array(
    '#type' => 'textfield',
    '#title' => t('twitter username'),
    '#size' => 50,
    '#description' => t('A valid twitter username.'),
    '#default_value' => !empty($conf['twitter_username']) ? $conf['twitter_username'] : 'nicklewisatx',
  );
  // no submit
  return $form;
}


/**
 * Submit function, note anything in the formstate[conf] automatically gets saved 
 */
function gtwitpane_pane_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['twitter_username'] = $form_state['values']['twitter_username'];
}


/**
 * This js handling kills kittens.
 */
function _gtwit_ghetto_js_that_is_bad($twitter_username) {
  $output = '<script src="http://widgets.twimg.com/j/2/widget.js"></script>';
  $output .= "<script>new TWTR.Widget({
			version:2,type:'profile',rpp:3,interval:6000,width:'auto',height:'auto',theme:{shell:{background:'#ffffff',color:'#000000'},
			tweets:{background:'#ffffff',color:'#000000',links:'#227eb3'}},
			features:{scrollbar:false,loop:false,live:false,hashtags:true,timestamp:true,avatars:false,behavior:'all'}}).render().setUser('$twitter_username').start();
  </script>";
  return $output;
}
