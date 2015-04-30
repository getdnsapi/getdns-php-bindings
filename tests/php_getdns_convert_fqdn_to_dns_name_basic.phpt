--TEST--
Test function php_getdns_convert_fqdn_to_dns_name() by calling it with its expected arguments
--FILE--
<?php

$fqdn = "www.getdnsapi.net";
$bindata = "";
$result = php_getdns_convert_fqdn_to_dns_name($fqdn, $bindata);
$unpacked = unpack("h*", $bindata);
var_dump($result, $fqdn, $unpacked);

?>
--EXPECT--
int(0)
string(17) "www.getdnsapi.net"
array(1) {
  [1]=>
  string(38) "307777779076564746e63716079630e6564700"
}

