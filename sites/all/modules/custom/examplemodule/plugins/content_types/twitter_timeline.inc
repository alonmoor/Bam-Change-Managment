<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Twitter timeline'),
  'description' => t('Shows a twitter timeline with basic configuration options.'),
  'category' => t('Social media'),
  'edit form' => 'examplemodule_twitter_timeline_edit_form',
  'render callback' => 'examplemodule_twitter_timeline_render',
  'admin info' => 'examplemodule_twitter_timeline_admin_info',
  'defaults' => array(
    'username' => 'wiifm',
    'tweets_to_show' => 5,
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function examplemodule_twitter_timeline_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing @tweets_to_show tweets from <em>@@username</em>.', array(
      '@tweets_to_show' => $conf['tweets_to_show'],
      '@username' => $conf['username'],
    ));
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function examplemodule_twitter_timeline_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['username'] = array(
    '#title' => t('Twitter username'),
    '#description' => t('The username of the twitter account in which to pull the tweets from.'),
    '#type' => 'textfield',
    '#default_value' => $conf['username'],
    '#required' => TRUE,
  );

  $form['tweets_to_show'] = array(
    '#title' => t('Number of tweets to show'),
    '#description' => t('Used to control the number of tweets shown on the page initially. Defaults to 5.'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(range(3, 12)),
    '#default_value' => $conf['tweets_to_show'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function examplemodule_twitter_timeline_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function examplemodule_twitter_timeline_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // initial content is blank
  $block->title = '';
  $block->content = '';

  // Include twitter javascript - by linking to the external file.
  drupal_add_js('//widgets.twimg.com/j/2/widget.js', 'external');

  // Add in the content
  $block->content .= '
    <script type="text/javascript">
      var t = new TWTR.Widget({
        version: 2,
        type: "profile",
        rpp: ' . check_plain($conf['tweets_to_show']) . ',
        interval: 30000,
        width: "300",
        height: "300",
        theme: {
          shell: {
            background: "#ededed",
            color: "#6a6a6a"
          },
          tweets: {
            background: "#fafafa",
            color: "#6a6a6a",
            links: "#6a6a6a"
          }
        },
        features: {
          avatars: false,
          hashtags: true,
          scrollbar: false,
          loop: true,
          live: true,
          behavior: "default"
        }
      });

      t.render().setUser("' . check_plain($conf['username']) . '").start();
    </script>';

  return $block;
}
