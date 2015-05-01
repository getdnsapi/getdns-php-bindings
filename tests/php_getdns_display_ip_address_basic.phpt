--TEST--
Test function php_getdns_display_ip_address() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 0;
$apiDict = php_getdns_context_get_api_information($context);
var_dump($result, $apiDict);

$alllDict = 0;
$result = php_getdns_dict_get_dict($apiDict, "all_context", $allDict);
var_dump($result);
$recList = 0;
$result = php_getdns_dict_get_list($allDict, "upstream_recursive_servers", $recList);
var_dump($result);
$result = php_getdns_list_get_dict($recList, 0, $recDict);
var_dump($result);
$bindata = "";
$result = php_getdns_dict_get_bindata($recDict, "address_data", $bindata);
var_dump($result);
$ipAddress = php_getdns_display_ip_address($bindata);
var_dump($ipAddress);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(0)
int(0)
int(0)
int(0)
string(%d) "%s"
