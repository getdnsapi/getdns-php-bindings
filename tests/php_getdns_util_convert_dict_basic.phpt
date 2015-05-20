--TEST--
Test function php_getdns_util_convert_dict() by calling it with its expected arguments
--FILE--
<?php

// Build a dictionary.
$dict = php_getdns_dict_create();
$result = php_getdns_dict_set_int($dict, "zero", 0);
$result = php_getdns_dict_set_int($dict, "one", 1);
$bindata = pack("C*", 0x77, 0x77, 0x77);
$result = php_getdns_dict_set_bindata($dict, "two", $bindata);
$indexArray = array("foo", "bar", "hello", "world");
$result = php_getdns_util_convert_array($indexArray, $tmpList);
$result = php_getdns_dict_set_list($dict, "three", $tmpList);
$assocArray = array("foo" => "foo", "bar" => "bar", "hello" => "hello", "world" => "world");
$result = php_getdns_util_convert_array($assocArray, $tmpDict);
$result = php_getdns_dict_set_dict($dict, "four", $tmpDict);

// Convert the dictionary to an array.
$dictArray = array();
$result = php_getdns_util_convert_dict($dict, $dictArray);
var_dump($result, $dictArray);
php_getdns_dict_destroy($dict);

?>
--EXPECTF--
int(0)
array(5) {
  ["four"]=>
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
  ["one"]=>
  int(1)
  ["three"]=>
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
  ["two"]=>
  string(3) "www"
  ["zero"]=>
  int(0)
}
