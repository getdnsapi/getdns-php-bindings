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

$userArg = NULL;
$result = php_getdns_context_get_update_callback($context, $userArg);
var_dump($result, $userArg);

$userArg[0] = "contextUpdateCallback";
$userArg[1] = "User args!";
$result = php_getdns_context_set_update_callback($context, $userArg);
var_dump($result);

$userArg2 = NULL;
$result = php_getdns_context_get_update_callback($context, $userArg2);
var_dump($result, $userArg2);

php_getdns_context_destroy($context);
?>
