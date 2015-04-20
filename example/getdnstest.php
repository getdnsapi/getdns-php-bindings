<?php

/**
 *
 * \file getdnstest.php
 * @Example function calls and processing for the getdns language binding for PHP.
 *
 */

/*
 * Copyright (c) 2015, NLNet Labs, Verisign, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the names of the copyright holders nor the
 *   names of its contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Verisign, Inc. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

  /**
   * Example callback function to process context change types.
   *
   * Parameters:
   * $changed: the numeric value that identifies the context element that's been updated.
   *
   * NOTE: For now the name of this function MUST be "phpGetDNSContextCallback". It's hard-coded
   * in the getdns PHP extension due to a limitation in the getdns API.
   */
  function phpGetDNSContextCallback($changed)
  {
    // Do something appropriate with the change type.
    if ($userArg != NULL) {
      var_dump($changed);
    }
  }

  /**
   * Example callback function to process getdns responses.
   *
   * Parameters:
   * $dict: the address of the getdns_dict structure that contains the response to the function call.
   * $callbackType: the reason for calling the callback.
   * $userArg: whatever the PHP client passed to the getdns async function call.
   */
  function php_echo_addresses($dict, $callbackType, $userArg)
  {
    // Do something appropriate with userArg.
    if ($userArg != NULL) {
      //var_dump($userArg);
    }

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
	$list = 0;
        $result = php_getdns_dict_get_list($dict, "just_address_answers",
	$list);
	$listLength = 0;
        $result = php_getdns_list_get_length($list, $listLength);
        for ($recCount = 0; $recCount < $listLength; $recCount++) {
	  $thisAddress = 0;
	  $binData = 0;
          $result = php_getdns_list_get_dict($list, $recCount,
	  $thisAddress);
          $result = php_getdns_dict_get_bindata($thisAddress, "address_data",
	  $binData);
          $result = php_getdns_display_ip_address($binData);
          echo "The address is " . $result . "\n";
        }
      break;
      case GETDNS_CALLBACK_CANCEL:
        echo "Callback cancelled.\n";
        break;
      case GETDNS_CALLBACK_TIMEOUT:
        echo "Callback timeout.\n";
        break;
      case GETDNS_CALLBACK_ERROR:
        echo "Callback error.\n";
        break;
      default:
        /* There shouldn't be any other values, but... */
        echo "Unknown callback type.\n";
    }
    php_getdns_dict_destroy($dict);
  }

  // Make sure the extension is loaded.
  if (extension_loaded("getdns")) {
    echo "Extension pre-loaded!\n";
    //print_r(get_extension_funcs("getdns"));
  }
  else {
    echo "Loading extension manually... ";
    dl("getdns.so");
    if (extension_loaded("getdns") == FALSE) {
      echo "failed!\n";
      exit();
    }
    echo "loaded!\n";
    //print_r(get_extension_funcs("getdns"));
  }

  echo "Creating context... ";
  $context = 0;
  $setFromOS = 1;
  // Note that $context is passed by reference.
  $result = php_getdns_context_create($context, $setFromOS);
  var_dump($result);
  if ($result == GETDNS_RETURN_GOOD) {
    echo "done.\n";
  }
  else {
    echo "error: " . $result . "\n";
  }

  // Test...
  $result = php_getdns_context_set_use_threads($context, 1);

  // Test...
  $apiDict = php_getdns_context_get_api_information($context);
  $apiInfo = php_getdns_pretty_print_dict($apiDict);
  echo "API info: " . $apiInfo . "\n";

  $name = "www.getdnsapi.net";
  $extensions = NULL;
  $response = 0;
  echo "\nSynchronously resolving " . $name . "... ";
  $result = php_getdns_address_sync($context, $name, $extensions, $response);
  if ($result == GETDNS_RETURN_GOOD) {
    echo "done.\n";
  }
  else {
    echo "error: " . $result . "\n";
  }
  //var_dump($result);
  // Confirm response status and retrieve the addresses from the response.
  $errCode = 0;
  $result = php_getdns_dict_get_int($response, "status", $errCode);
  if ($errCode != GETDNS_RESPSTATUS_GOOD) {
    var_dump($errCode);
    $errMsg = "";
    $errMsgLen = 0;
    $result = php_getdns_strerror($errCode, $errMsg, $errMsgLen);
    echo "Error " . $errCode . " " . $errMsg . "\n";
    exit($result);
  }
  $list = 0;
  $result = php_getdns_dict_get_list($response, "just_address_answers",
  $list);
  //echo "list:\n"; var_dump($list);
  $listLength = 0;
  $result = php_getdns_list_get_length($list, $listLength);
  //echo "listLength:\n"; var_dump($listLength);
  for ($recCount = 0; $recCount < $listLength; $recCount++) {
    $thisAddress = 0;
    $binData = 0;
    $result = php_getdns_list_get_dict($list, $recCount,
    $thisAddress);
    $result = php_getdns_dict_get_bindata($thisAddress, "address_data",
    $binData);
    $result = php_getdns_display_ip_address($binData);
    echo "The address is " . $result . "\n";
  }
  php_getdns_dict_destroy($response);

  echo "\nAsynchronously resolving " . $name . "...\n";
  $transID = (double) 0; // Must be a non-zero integer to get populated by the getdns library.
  $userArgs[0] = "php_echo_addresses";
  $userArgs[1] = "User args test 1";
  $result = php_getdns_address($context, $name, $extensions, $userArgs, $transID);
  if ($result == GETDNS_RETURN_GOOD) {
    echo "done; transID " . $transID . "\n";
    php_getdns_context_run($context);
  }
  else {
    echo "error: " . $result . "\n";
  }

  echo "\nAsynchronously resolving " . $name . " with dnssec_return_only_secure set...\n";
  $transID = (double) 1;
  $userArgs[0] = "php_echo_addresses";
  $userArgs[1] = "User args test 2";
  $extensions = php_getdns_dict_create();
  if ($extensions == NULL) {
    echo "Failed to create dictionary for extensions.\n";
    exit(-1);
  }
  $result = php_getdns_dict_set_int($extensions, "dnssec_return_only_secure", GETDNS_EXTENSION_TRUE);
  if ($result != GETDNS_RETURN_GOOD) {
    echo "error: " . $result . "\n";
    exit($result);
  }
  $result = php_getdns_address($context, $name, $extensions, $userArgs, $transID);
  if ($result == GETDNS_RETURN_GOOD) {
    echo "done; transID " . $transID . "\n";
    php_getdns_context_run($context);
  }
  else {
    echo "error: " . $result . "\n";
  }
  $name = "www.dnssec-failed.org";
  $userArgs[0] = "php_echo_addresses";
  $userArgs[1] = "User args test 3";
  $transID = (double) 2;
  echo "\nAsynchronously resolving " . $name . " with dnssec_return_only_secure set...\n";
  $result = php_getdns_address($context, $name, $extensions, $userArgs, $transID);
  if ($result == GETDNS_RETURN_GOOD) {
    echo "done; transID " . $transID . "\n";
    php_getdns_context_run($context);
  }
  else {
    echo "error: " . $result . "\n";
  }
  php_getdns_dict_destroy($extensions);

  // Test getting and setting namespaces.
  $namespaces = array();
  $result = php_getdns_context_get_namespaces($context, $namespaces);
  echo "\nNamespace values:\n";
  var_dump($result, $namespaces);
  $arrayCount = count($namespaces);
  $result = php_getdns_context_set_namespaces($context, $arrayCount, $namespaces);
  var_dump($result, $namespaces);

  // Test event loop setting.
  // NOTE: The call to destroy the context below will cause a segmentation fault if you call this.
  //$result = php_getdns_context_set_eventloop($context);
  //var_dump($result);

  // Set the EDNS DO bit.
  echo "Testing getting/setting the EDNS DO bit...\n";
  $ednsDOBit = FALSE;
  $result = php_getdns_context_get_edns_do_bit($context, $ednsDOBit);
  var_dump($result, $ednsDOBit);
  $ednsDOBit = TRUE;
  $result = php_getdns_context_set_edns_do_bit($context, $ednsDOBit);
  var_dump($result, $ednsDOBit);
  $ednsDOBit = FALSE;
  $result = php_getdns_context_set_edns_do_bit($context, $ednsDOBit);
  var_dump($result, $ednsDOBit);

  // Set the timeout.
  echo "Testing getting/setting the timeout value...\n";
  $timeout = (double) 0;
  $result = php_getdns_context_get_timeout($context, $timeout);
  var_dump($result, $timeout);
  $timeout = (double) 10000;
  $result = php_getdns_context_set_timeout($context, $timeout);
  var_dump($result, $timeout);
  $timeout = (double) 0;
  $result = php_getdns_context_get_timeout($context, $timeout);
  var_dump($result, $timeout);

  // Clean up.
  php_getdns_context_destroy($context);
?>
