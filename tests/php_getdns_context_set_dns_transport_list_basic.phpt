--TEST--
Test function php_getdns_context_set_dns_transport_list() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$transports = array(GETDNS_TRANSPORT_UDP, GETDNS_TRANSPORT_TCP, GETDNS_TRANSPORT_TLS);
$transCount = count($transports);
$result = php_getdns_context_set_dns_transport_list($context, $transCount, $transports);
var_dump($result, $transports);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
array(3) {
  [0]=>
  int(1200)
  [1]=>
  int(1201)
  [2]=>
  int(1202)
}
