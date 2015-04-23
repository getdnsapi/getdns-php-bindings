--TEST--
Test function php_getdns_hostname() by calling it with its expected arguments
--FILE--
<?php

function php_echo_name($dict, $callbackType, $userArg)
{
    php_getdns_dict_destroy($dict);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$address = php_getdns_dict_create();
$result = php_getdns_dict_set_bindata($address, "address_type", "IPv4");
var_dump($result);

$result = php_getdns_dict_set_bindata($address, "address_data", "\x08\x08\x08\x08");
var_dump($result);

$extensions = NULL;
$transID = (double) 0;
$userArgs[0] = "php_echo_name";
$userArgs[1] = "User args test 1";
$result = php_getdns_hostname($context, $address, $extensions, $userArgs, $transID);
var_dump($result);
if ($result == GETDNS_RETURN_GOOD) {
    php_getdns_context_run($context);
}

php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(0)
int(0)
