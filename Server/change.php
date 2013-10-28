<?php

function setColor($color){
    //Writes the user defined color to file.txt
    
    $file = 'file.txt';
    $handle = fopen($file, 'w') or die('Cannot open file:  '.$file);
    echo $color;
    fwrite($handle, $color);
}


if (!isset($_GET['c']) or $_GET['c'] == '') {
    //Valadates GET varable
    echo 'ERROR - No color defined. Stopping...';
    die();
    
//Makes sure color is green, red, or blue, then calls setColor.
} elseif ($_GET['c'] == 'green') {
    setColor($_GET['c']);
} elseif ($_GET['c'] == 'red') {
    setColor($_GET['c']);
} elseif ($_GET['c'] == 'blue') {
    setColor($_GET['c']);
} else {
    echo 'ERROR: The color chosen was invalid. Stopping...';
    die();
}


?>