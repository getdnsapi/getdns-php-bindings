--TEST--
Test function php_getdns_validate_dnssec() by calling it with its expected arguments
--FILE--
<?php

function php_callback($dict, $callbackType, $userArg, $transID)
{
    $status = 0;
    $result = php_getdns_dict_get_int($dict, "status", $status);
    var_dump($status);
    if ($status != GETDNS_RESPSTATUS_GOOD) {
        return;
    }

    // Parse the response to get the records to be validated.
    $rTree = 0;
    $result = php_getdns_dict_get_list($dict, "replies_tree", $rTree);
    var_dump($result, $rTree);
    $answer = 0;
    $result = php_getdns_list_get_dict($rTree, 0, $answer);
    var_dump($result, $answer);
    $toVal = 0;
    $result = php_getdns_dict_get_list($answer, "answer", $toVal);
    var_dump($result, $toVal);

    // Get the support records.
    $supRecs = 0;
    $result = php_getdns_dict_get_list($dict, "validation_chain", $supRecs);
    var_dump($result, $supRecs);

    // Get the trust anchor.
    $anchorDate = 0;
    $trustAnchor = php_getdns_root_trust_anchor($anchorDate);
    var_dump($trustAnchor);

    // Validate!
    $result = php_getdns_validate_dnssec($toVal, $supRecs, $trustAnchor);
    var_dump($result);

    /*$toValStr = php_getdns_pretty_print_list($toVal);
    var_dump($toValStr);
    $supRecsStr = php_getdns_pretty_print_list($supRecs);
    var_dump($supRecsStr);
    $trustAnchorStr = php_getdns_pretty_print_list($trustAnchor);
    var_dump($trustAnchorStr);*/

    php_getdns_dict_destroy($dict);
}

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

/*
 * Note that the getdns_validate_dnssec() function in the
 * getdns library is currenly known to not produce correct
 * results for all query types. NS record queries, for example,
 * don't work because the library has issues with compressed
 * names. The query used here should produce a GETDNS_DNSSEC_SECURE
 * (400) result.
 */
$name = "www.getdnsapi.net";
$reqType = GETDNS_RRTYPE_A;

// Set extensions to return DNSSEC validation information.
$extensions = php_getdns_dict_create();
$result = php_getdns_dict_set_int($extensions, "dnssec_return_validation_chain", GETDNS_EXTENSION_TRUE);

$transID = "";
$userArgs[0] = "php_callback";
$userArgs[1] = "User args test 1";
$result = php_getdns_general($context, $name, $reqType, $extensions, $userArgs, $transID);
php_getdns_dict_destroy($extensions);
var_dump($result, $transID);
if ($result == GETDNS_RETURN_GOOD) {
    php_getdns_context_run($context);
}

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
string(16) "%s"
int(900)
int(0)
int(%d)
int(0)
int(%d)
int(0)
int(%d)
int(0)
int(%d)
int(%d)
int(400)
