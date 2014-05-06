/**
 * Created by alon on 24/04/14.
 */
var userAgent = navigator.userAgent.toString().toLowerCase();
if ((userAgent.indexOf('safari') != -1) && !(userAgent.indexOf('chrome') != -1)) {
    alert('We should be on Safari only!');
}

