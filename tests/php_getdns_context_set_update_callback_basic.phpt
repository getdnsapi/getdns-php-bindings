--TEST--
Test function php_getdns_context_set_update_callback() by calling it with its expected arguments
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
$userArg[0] = "contextUpdateCallback";
$userArg[1] = "User args!";
$result = php_getdns_context_set_update_callback($context, $userArg);
var_dump($result);
$result = php_getdns_context_set_limit_outstanding_queries($context, 5);
var_dump($result);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(606)
array(2) {
  [0]=>
  string(21) "contextUpdateCallback"
  [1]=>
  string(10) "User args!"
}
int(0)
