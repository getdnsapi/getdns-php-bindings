--TEST--
Test function php_getdns_convert_alabel_to_ulabel() by calling it with its expected arguments
--FILE--
<?php

$uLabel = "mañana.com";
$aLabel = php_getdns_convert_ulabel_to_alabel($uLabel);
var_dump($aLabel);

?>
--EXPECT--
string(17) "xn--maana-pta.com"
