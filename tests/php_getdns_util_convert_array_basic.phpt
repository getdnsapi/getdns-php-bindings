--TEST--
Test function php_getdns_util_convert_array() by calling it with its expected arguments
--FILE--
<?php

// Test conversion of an indexed array to a list.
$test1[0] = 0;
$test1[1] = 1;
$test1[2] = pack("C*", 0x77, 0x77, 0x77);
$test1[3] = array("foo", "bar", "hello", "world");
$test1[4] = array("foo" => "foo", "bar" => "bar", "hello" => "hello", "world" => "world");
$outVal1 = 0;
$result = php_getdns_util_convert_array($test1, $outVal1);
$pp = php_getdns_pretty_print_list($outVal1);
var_dump($test1, $pp);
php_getdns_list_destroy($outVal1);

// Test conversion of an associative array to a dictionary.
$test2["zero"] = 0;
$test2["one"] = 1;
$test2["two"] = pack("C*", 0x77, 0x77, 0x77);
$test2["three"] = array("foo", "bar", "hello", "world");
$test2["four"] = array("foo" => "foo", "bar" => "bar", "hello" => "hello", "world" => "world");
$outVal2 = 0;
$result = php_getdns_util_convert_array($test2, $outVal2);
$pp = php_getdns_pretty_print_dict($outVal2);
var_dump($test2, $pp);
php_getdns_dict_destroy($outVal2);

?>
--EXPECTF--
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
    ["foo"]=>
    string(3) "foo"
    ["bar"]=>
    string(3) "bar"
    ["hello"]=>
    string(5) "hello"
    ["world"]=>
    string(5) "world"
  }
}
string(287) "[
  0,
  1,
   <bindata of "www">,
  [
     <bindata of "foo">,
     <bindata of "bar">,
     <bindata of "hello">,
     <bindata of "world">
  ],
  {
    "bar": <bindata of "bar">,
    "foo": <bindata of "foo">,
    "hello": <bindata of "hello">,
    "world": <bindata of "world">
  }
]"
array(5) {
  ["zero"]=>
  int(0)
  ["one"]=>
  int(1)
  ["two"]=>
  string(3) "www"
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
  ["four"]=>
  array(4) {
    ["foo"]=>
    string(3) "foo"
    ["bar"]=>
    string(3) "bar"
    ["hello"]=>
    string(5) "hello"
    ["world"]=>
    string(5) "world"
  }
}
string(329) "{
  "four":
  {
    "bar": <bindata of "bar">,
    "foo": <bindata of "foo">,
    "hello": <bindata of "hello">,
    "world": <bindata of "world">
  },
  "one": 1,
  "three":
  [
     <bindata of "foo">,
     <bindata of "bar">,
     <bindata of "hello">,
     <bindata of "world">
  ],
  "two": <bindata of "www">,
  "zero": 0
}"
