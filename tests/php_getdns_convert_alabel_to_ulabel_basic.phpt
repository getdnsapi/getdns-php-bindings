--TEST--
Test function php_getdns_convert_alabel_to_ulabel() by calling it with its expected arguments
--FILE--
<?php

$aLabel = "xn--maana-pta.com";
$uLabel = php_getdns_convert_alabel_to_ulabel($aLabel);
var_dump($uLabel);

?>
--EXPECT--
string(11) "mañana.com"
