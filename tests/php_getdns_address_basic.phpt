--TEST--
Test function php_getdns_address() by calling it with its expected arguments
--FILE--
<?php

function php_echo_addresses($dict, $callbackType, $userArg, $transID)
{
    var_dump($callbackType, $transID);
    php_getdns_dict_destroy($dict);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$name = "www.getdnsapi.net";
$extensions = NULL;
$transID = NULL;
$userArgs[0] = "php_echo_addresses";
$userArgs[1] = "User args test 1";
$result = php_getdns_address($context, $name, $extensions, $userArgs, $transID);
var_dump($result, $transID);
if ($result == GETDNS_RETURN_GOOD) {
    php_getdns_context_run($context);
}

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
NULL
int(700)
string(16) "%s"
