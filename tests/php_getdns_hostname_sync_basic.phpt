--TEST--
Test function php_getdns_hostname_sync() by calling it with its expected arguments
--FILE--
<?php

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
$response = 0;
$result = php_getdns_hostname_sync($context, $address, $extensions, $response);
var_dump($result);

php_getdns_dict_destroy($address);
php_getdns_dict_destroy($response);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(0)
int(0)
