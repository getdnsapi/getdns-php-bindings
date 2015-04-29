--TEST--
Test function php_getdns_hostname() by calling it with its expected arguments
--FILE--
<?php

function php_echo_name($dict, $callbackType, $userArg, $transID)
{
    var_dump($callbackType, $transID);
    php_getdns_dict_destroy($dict);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$address = php_getdns_dict_create();
$result = php_getdns_dict_set_bindata($address, "address_type", "IPv4");
var_dump($result);

$binData = pack("n*", 0x0808, 0x0808);
$result = php_getdns_dict_set_bindata($address, "address_data", $binData);
var_dump($result);

$extensions = NULL;
$transID = "";
$userArgs[0] = "php_echo_name";
$userArgs[1] = "User args test 1";
$result = php_getdns_hostname($context, $address, $extensions, $userArgs, $transID);
var_dump($result, $transID);
if ($result == GETDNS_RETURN_GOOD) {
    php_getdns_context_run($context);
}

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(0)
int(0)
string(16) "%s"
int(700)
string(16) "%s"
