--TEST--
Test function php_getdns_root_trust_anchor() by calling it with its expected arguments
--FILE--
<?php

$anchorDate = 0;
$list = php_getdns_root_trust_anchor($anchorDate);
var_dump($list, $anchorDate);

?>
--EXPECTF--
int(%d)
int(%d)
