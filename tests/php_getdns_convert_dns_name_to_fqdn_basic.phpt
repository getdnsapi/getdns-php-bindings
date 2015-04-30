--TEST--
Test function php_getdns_convert_dns_name_to_fqdn() by calling it with its expected arguments
--FILE--
<?php

$bindata = pack("h*", "307777779076564746e63716079630e6564700");
$fqdn = "";
$result = php_getdns_convert_dns_name_to_fqdn($bindata, $fqdn);
$unpacked = unpack("h*", $bindata);
var_dump($result, $unpacked, $fqdn);

?>
--EXPECT--
int(0)
array(1) {
  [1]=>
  string(38) "307777779076564746e63716079630e6564700"
}
string(18) "www.getdnsapi.net."
