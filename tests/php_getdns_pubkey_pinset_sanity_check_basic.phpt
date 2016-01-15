--TEST--
Test function php_getdns_pubkey_pinset_sanity_check() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$pin1 = "pin-sha256=\"E9CZ9INDbd+2eRQozYqqbQ2yXLVKB9+xcprMF+44U1g=\"";
$pin2 = "pin-sha256=\"E9CZ9INDbd+2eRQozYqqbQ2yXLVKB9+xcprMF+44U1g=\"";
$dict1 = php_getdns_pubkey_pin_create_from_string($context, $pin1);
$dict2 = php_getdns_pubkey_pin_create_from_string($context, $pin2);
var_dump($dict1);
var_dump($dict2);

$list = php_getdns_list_create();
var_dump($list);

$result = php_getdns_list_set_dict($list, 0, $dict1);
var_dump($result);
$ppList = php_getdns_pretty_print_list($list);
var_dump($ppList);

$result = php_getdns_list_set_dict($list, 1, $dict2);
var_dump($result);
$ppList = php_getdns_pretty_print_list($list);
var_dump($ppList);

$errorList = php_getdns_list_create();
var_dump($errorList);
$result = php_getdns_pubkey_pinset_sanity_check($list, $errorList);
$ppList = php_getdns_pretty_print_list($errorList);
var_dump($result, $ppList);
php_getdns_list_destroy($errorList);

$errorList = 0;
$result = php_getdns_pubkey_pinset_sanity_check($list, $errorList);
$ppList = php_getdns_pretty_print_list($errorList);
var_dump($result, $ppList);

php_getdns_list_destroy($list);
php_getdns_dict_destroy($dict1);
php_getdns_dict_destroy($dict2);

?>
--EXPECTF--
int(%d)
int(%d)
int(%d)
int(0)
string(112) "%a"
int(0)
string(222) "%a"
int(%d)
int(0)
string(2) "[]"
int(0)
NULL
