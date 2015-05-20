--TEST--
Test function php_getdns_util_convert_list() by calling it with its expected arguments
--FILE--
<?php

// Build a list.
$list = php_getdns_list_create();
$result = php_getdns_list_set_int($list, 0, 0);
$result = php_getdns_list_set_int($list, 1, 1);
$bindata = pack("C*", 0x77, 0x77, 0x77);
$result = php_getdns_list_set_bindata($list, 2, $bindata);
$indexArray = array("foo", "bar", "hello", "world");
$result = php_getdns_util_convert_array($indexArray, $tmpList);
$result = php_getdns_list_set_list($list, 3, $tmpList);
$assocArray = array("foo" => "foo", "bar" => "bar", "hello" => "hello", "world" => "world");
$result = php_getdns_util_convert_array($assocArray, $tmpDict);
$result = php_getdns_list_set_dict($list, 4, $tmpDict);

// Convert the list to an array.
$listArray = array();
$result = php_getdns_util_convert_list($list, $listArray);
var_dump($result, $listArray);
php_getdns_list_destroy($list);

?>
--EXPECTF--
int(0)
array(5) {
  [0]=>
  int(0)
  [1]=>
  int(1)
  [2]=>
  string(3) "www"
  [3]=>
  array(4) {
    [0]=>
    string(3) "foo"
    [1]=>
    string(3) "bar"
    [2]=>
    string(5) "hello"
    [3]=>
    string(5) "world"
  }
  [4]=>
  array(4) {
    ["bar"]=>
    string(3) "bar"
    ["foo"]=>
    string(3) "foo"
    ["hello"]=>
    string(5) "hello"
    ["world"]=>
    string(5) "world"
  }
}
