<?php
/**
 * Created by PhpStorm.
 * User: alon
 * Date: 22/04/14
 * Time: 12:07
 */





// Add 'CLICK ME!' to every link.
function batoverrides_preprocess_link(&$variables) {
   // $variables['text'] .= 'CLICK ME!';
}

//function batoverrides_preprocess(&$variables ,$hook) {
//
//
//    if ($hook== 'page'){
//        static $i;
//        kpr($i .''. $hook);
//        $i++;
//    }
//}


function batoverrides_preprocess_page(&$variables) {


   $slogans =array(
       t('Life is good.'),
       t('aaaaaaaaaaaaaaaaaa.'),
       t('sssssssssss.'),
       t('ddddddddddd.'),
       t('ffffffffffff.'),
       t('gggggggggggggg.'),
       t('hhhhhhhhhhhhhhh.'),
       t('jjjjjjjjjjjjjjjj.'),
       t('kkkkkkkkkkkkkkkkkkkkk.'),
   );
  // $slogans[]=t('Life is good.');


    $slogan =$slogans[array_rand($slogans)];
    $variables['site_slogan']= $slogan ;

//$variables['site_slogan']= "ALON SITE";
//   print "wwwwwwwwwwwww";
 //  kpr($variables);


 //add new variable
if($variables['logged_in']){


    $variables['footer_message'] = t('Welcom @username ,WE loves you.',array('@username' => $variables['user']-> name));

}else{


    $variables['footer_message'] = t('I love you');


}


//kpr($variables);



    if($variables['is_front'] == TRUE){

       // drupal_add_css(path_to_theme(). '/css/front.css',array('group' => CSS_THEME));
        drupal_add_css(path_to_theme(). '/css/front.css',array('group' => 1000,'weight' => -10));
        //drupal_add_js(path_to_theme(). '/js/test.js.css',array('group' => 1000,'weight' => -10));
        drupal_add_js(drupal_get_path('theme', 'batoverrides') .'/js/test.js', 'file');
    }



}












function batoverrides_preprocess_node(&$variables) { //effect only page contentype

   if($variables['type']== 'article'){

     $node=$variables['node'];
       $variables['submitted_day'] = format_date($node->created , 'custom' , 'j');
       $variables['submitted_month'] = format_date($node->created , 'custom' , 'M');
       $variables['submitted_year'] = format_date($node->created , 'custom' , 'Y');



   }


    if($variables['type']=='page'){

    $today = strtolower(date('l'));

    //  $variables['theme_hook_suggestions'][]='node__wednesday';//add one more element to the array of  theme_hook_suggestions talk about template
        //then add underscours the template themself use for a specific dushes -> in the kpr we can see the added node

        $variables['theme_hook_suggestions'][]='node__'.$today;
        $variables['dat_of_the_week']=$today;
       // kpr($variables);
    }


}








function batoverrides_breadcrumb($variables) {
    $breadcrumb = $variables['breadcrumb'];

    if (!empty($breadcrumb)) {
        // Provide a navigational heading to give context for breadcrumb links to
        // screen-reader users. Make the heading invisible with .element-invisible.
        $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

        $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '  9999</div>';
        return $output;
    }
}

function batoverrides_username($variables) {
    if (isset($variables['link_path'])) {
        // We have a link path, so we should generate a link using l().
        // Additional classes may be added as array elements like
        // $variables['link_options']['attributes']['class'][] = 'myclass';

        $title=drupal_get_title();
        echo "$title zzzzzzzzzzzzzzzzzzzzzzz";
        $output = l($variables['name'] . $variables['extra'], $variables['link_path'], $variables['link_options'] );
    }
    else {
        // Modules may have added important attributes so they must be included
        // in the output. Additional classes may be added as array elements like
        // $variables['attributes_array']['class'][] = 'myclass';
        $output = '<span' . drupal_attributes($variables['attributes_array']) . '>' . $variables['name'] . $variables['extra'] . ' 4444</span>';
    }
    return $output;
}






//theme_username()

function batoverrides_preprocess_username(&$variables){


 $account = user_load($variables['account']->uid);
 //kpr($variables);
  //  kpr($account);

    if(isset($account->field_real_name[LANGUAGE_NONE][0]['safe_value'])){//safe ->not contains js and else

        $variables['name']=$account->field_real_name[LANGUAGE_NONE][0]['safe_value'];

    }

}




function batoverrides_field__field_tags($variables) {
    $output = '';
    kpr($variables);
    // Render the label, if it's not hidden.

    foreach($variables['items'] as $delta => $item){
        $item['#options']['attributes'] += $variables['item_attributes_array'][$delta];
        $links[] =drupal_render($item);
    }

    $output .= implode(',' , $links);
    return $output;
}





function batoverrides_field__field_tags__article($variables) {
    $output = '';
    kpr($variables);
    // Render the label, if it's not hidden.

    foreach($variables['items'] as $delta => $item){

        $item['#options']['attributes'] += $variables['item_attributes_array'][$delta]; //+= merge the array
        $links[] =drupal_render($item);
    }

    $output .= implode(',' , $links);

    return $output;
}







function batoverrides_field__field($variables) {
    $output = '';
    kpr($variables);
    // Render the label, if it's not hidden.

    foreach($variables['items'] as $delta => $item){

        $item['#options']['attributes'] += $variables['item_attributes_array'][$delta]; //+= merge the array
        $links[] =drupal_render($item);
    }

    $output .= implode(',' , $links);

    return $output;
}


function batoverrides_css_alter(&$css){

    unset($css['modules/system/system.menus.css']);

    //kpr($css);


}



function batoverrides_page_alter(&$page){


//    if(arg(0) == 'node' && is_numeric(arg(1))){
//
//       $nid =arg(0);
//       $image = $page['content']['system_main']['nodes'][$nid]['field_image'];
//        array_unshift($page['sidebar_first'],array ('image' => $image));
//
//
//    }




   kpr($page);


}