--TEST--
Test function php_getdns_context_get_edns_do_bit() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);

$ednsDOBit = FALSE;
$result = php_getdns_context_get_edns_do_bit($context, $ednsDOBit);
var_dump($result, $ednsDOBit);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
bool(%s)
