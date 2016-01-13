--TEST--
Test function php_getdns_rr_dict2wire() by calling it with its expected arguments
--FILE--
<?php

function php_echo_addresses($dict, $callbackType, $userArg, $transID)
{
    switch ($callbackType) {
      case GETDNS_CALLBACK_COMPLETE:
        // Confirm response status and retrieve the addresses from the response.
        $errCode = 0;
        $result = php_getdns_dict_get_int($dict, "status", $errCode);
        if ($errCode != GETDNS_RESPSTATUS_GOOD) {
          $errMsg = "";
          $errMsgLen = 0;
          $result = php_getdns_strerror($errCode, $errMsg, $errMsgLen);
          echo "Error " . $errCode . ": " . $errMsg . "\n";
          //exit($errCode);
          break;
        }

        $rTree = 0;
        $result = php_getdns_dict_get_list($dict, "replies_tree", $rTree);
        var_dump($result, $rTree);

        $answer = 0;
        $result = php_getdns_list_get_dict($rTree, 0, $answer);
        var_dump($result, $answer);

        $list = 0;
        $result = php_getdns_dict_get_list($answer, "authority", $list);
        var_dump($result, $list);

        $reply = 0;
        $result = php_getdns_list_get_dict($list, 0, $reply);
        var_dump($result, $reply);

        $wire = "";
        $wireSize = 0;
        $result = php_getdns_rr_dict2wire($reply, $wire, $wireSize);
        var_dump($result, $wire, $wireSize);
      break;
      case GETDNS_CALLBACK_CANCEL:
        break;
      case GETDNS_CALLBACK_TIMEOUT:
        break;
      case GETDNS_CALLBACK_ERROR:
        break;
      default:
    }
    php_getdns_dict_destroy($dict);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);

$name = "www.getdnsapi.net";
$reqType = GETDNS_RRTYPE_NS;
$extensions = NULL;
$transID = "";
$userArgs[0] = "php_echo_addresses";
$userArgs[1] = "User args test 1";
$result = php_getdns_general($context, $name, $reqType, $extensions, $userArgs, $transID);
if ($result == GETDNS_RETURN_GOOD) {
    php_getdns_context_run($context);
}

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(%d)
int(0)
int(%d)
int(0)
int(%d)
int(0)
int(%d)
int(0)
string(83) "%a"
int(83)
