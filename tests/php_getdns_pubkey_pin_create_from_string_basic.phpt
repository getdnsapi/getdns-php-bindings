--TEST--
Test function php_getdns_pubkey_pin_create_from_string() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$pin = "pin-sha256=\"E9CZ9INDbd+2eRQozYqqbQ2yXLVKB9+xcprMF+44U1g=\"";
$dict = php_getdns_pubkey_pin_create_from_string($context, $pin);
var_dump($dict);
php_getdns_dict_destroy($dict);
$dict = 0;

php_getdns_context_destroy($context);
$context = 0;

$dict = php_getdns_pubkey_pin_create_from_string($context, $pin);
var_dump($dict);

$pin="";
$dict = php_getdns_pubkey_pin_create_from_string($context, $pin);
var_dump($dict);

?>
--EXPECTF--
int(0)
int(%d)
int(%d)
int(0)
