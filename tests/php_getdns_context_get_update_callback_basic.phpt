--TEST--
Test function php_getdns_context_get_update_callback() by calling it with its expected arguments
--FILE--
<?php

function contextUpdateCallback($changed, $userArg)
{
    // Check the arguments.
    var_dump($changed);
    var_dump($userArg);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$userArg1 = NULL;
$result = php_getdns_context_get_update_callback($context, $userArg1);
var_dump($result, $userArg1);

$userArg1[0] = "contextUpdateCallback";
$userArg1[1] = "User args!";
$result = php_getdns_context_set_update_callback($context, $userArg1);
var_dump($result);

$userArg2 = NULL;
$result = php_getdns_context_get_update_callback($context, $userArg2);
var_dump($result, $userArg2);

php_getdns_context_destroy($context);
?>
--EXPECT--
int(0)
int(0)
NULL
int(0)
int(0)
array(2) {
  [0]=>
  string(21) "contextUpdateCallback"
  [1]=>
  string(10) "User args!"
}
