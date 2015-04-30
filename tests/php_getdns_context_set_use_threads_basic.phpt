--TEST--
Test function php_getdns_context_set_use_threads() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$useThreads = TRUE;
$result = php_getdns_context_set_use_threads($context, $useThreads);
var_dump($result, $useThreads);
$useThreads = FALSE;
$result = php_getdns_context_set_use_threads($context, $useThreads);
var_dump($result, $useThreads);

php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
bool(true)
int(0)
bool(false)
