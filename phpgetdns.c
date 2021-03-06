/**
 *
 * phpgetdns.c
 *
 * PHP version 5
 * 
 * @license TBD
 *
 * @package getdns language bindings header file for PHP.
 * @author Scott Hollenbeck <shollenbeck@verisign.com>
 *
 */

/*
 * @copyright Copyright (c) 2015, NLNet Labs, Verisign, Inc.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_getdns.h"
#include "getdns.h"
#include "getdns_extra.h"

ZEND_DECLARE_MODULE_GLOBALS(getdns)

ZEND_BEGIN_ARG_INFO_EX(address_svc_args, 0, 0, 6)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(0, userArg)
    ZEND_ARG_INFO(1, transID)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(address_svc_sync_args, 0, 0, 4)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(1, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(bindata_only_args, 0, 0, 1)
    ZEND_ARG_INFO(0, bindata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(cancel_callback_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, transID)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_create_args, 0, 0, 2)
    ZEND_ARG_INFO(1, context)
    ZEND_ARG_INFO(0, setFromOS)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_get_update_callback_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(1, userArg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_get_value_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(1, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_only_args, 0, 0, 1)
    ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_set_array_args, 0, 0, 3)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, count)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_set_update_callback_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, userArg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(context_set_value_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(convert_bindata_string_args, 0, 0, 2)
    ZEND_ARG_INFO(0, bindata)
    ZEND_ARG_INFO(1, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(convert_string_bindata_args, 0, 0, 2)
    ZEND_ARG_INFO(0, string)
    ZEND_ARG_INFO(1, bindata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(date_time_args, 0, 0, 1)
    ZEND_ARG_INFO(1, dateTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict_get_names_args, 0, 0, 2)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(1, names)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict_get_value_args, 0, 0, 3)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(1, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict_only_args, 0, 0, 1)
    ZEND_ARG_INFO(0, dict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict_remove_args, 0, 0, 2)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict_set_value_args, 0, 0, 3)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict2wire_args, 0, 0, 3)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(1, wire)
    ZEND_ARG_INFO(1, wireSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict2str_args, 0, 0, 2)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(1, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dict2strlen_args, 0, 0, 3)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(1, str)
    ZEND_ARG_INFO(1, strLen)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(errorstr_args, 0, 0, 1)
    ZEND_ARG_INFO(0, errorValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(fp2rr_list_args, 0, 0, 4)
    ZEND_ARG_INFO(0, inFile)
    ZEND_ARG_INFO(1, list)
    ZEND_ARG_INFO(0, origin)
    ZEND_ARG_INFO(0, defaultTTL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(general_args, 0, 0, 7)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, reqType)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(0, userArg)
    ZEND_ARG_INFO(1, transID)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(general_sync_args, 0, 0, 5)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, reqType)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(1, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hostname_args, 0, 0, 6)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, address)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(0, userArg)
    ZEND_ARG_INFO(1, transID)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hostname_sync_args, 0, 0, 4)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, address)
    ZEND_ARG_INFO(0, extensions)
    ZEND_ARG_INFO(1, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(list_get_length_args, 0, 0, 2)
    ZEND_ARG_INFO(0, list)
    ZEND_ARG_INFO(1, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(list_get_value_args, 0, 0, 3)
    ZEND_ARG_INFO(0, list)
    ZEND_ARG_INFO(0, index)
    ZEND_ARG_INFO(1, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(list_only_args, 0, 0, 1)
    ZEND_ARG_INFO(0, list)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(list_set_value_args, 0, 0, 3)
    ZEND_ARG_INFO(0, list)
    ZEND_ARG_INFO(0, index)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(one_string_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(pin_create_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(pinset_check_args, 0, 0, 2)
    ZEND_ARG_INFO(0, pinset)
    ZEND_ARG_INFO(1, errorlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(pretty_print_value_args, 0, 0, 1)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(pretty_print_json_value_args, 0, 0, 2)
    ZEND_ARG_INFO(0, value)
    ZEND_ARG_INFO(0, prettyPrint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(set_return_dnssec_status_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, enabled)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(set_use_threads_args, 0, 0, 2)
    ZEND_ARG_INFO(0, context)
    ZEND_ARG_INFO(0, useThreads)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(str2rr_args, 0, 0, 4)
    ZEND_ARG_INFO(0, rrStr)
    ZEND_ARG_INFO(1, rrDict)
    ZEND_ARG_INFO(0, origin)
    ZEND_ARG_INFO(0, defaultTTL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(util_convert_array_args, 0, 0, 2)
    ZEND_ARG_INFO(0, phpArray)
    ZEND_ARG_INFO(1, dictOrList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(util_convert_dict_args, 0, 0, 2)
    ZEND_ARG_INFO(0, dict)
    ZEND_ARG_INFO(1, phpArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(util_convert_list_args, 0, 0, 2)
    ZEND_ARG_INFO(0, list)
    ZEND_ARG_INFO(1, phpArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(validate_dnssec_args, 0, 0, 3)
    ZEND_ARG_INFO(0, toValidate)
    ZEND_ARG_INFO(0, supportRecords)
    ZEND_ARG_INFO(0, trustAnchors)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(wire2rr_dict_args, 0, 0, 3)
    ZEND_ARG_INFO(0, wire)
    ZEND_ARG_INFO(0, wireSize)
    ZEND_ARG_INFO(1, dict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(wire2rr_dict_buf_args, 0, 0, 3)
    ZEND_ARG_INFO(0, wire)
    ZEND_ARG_INFO(1, wireSize)
    ZEND_ARG_INFO(1, dict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(wire2rr_dict_scan_args, 0, 0, 3)
    ZEND_ARG_INFO(1, wire)
    ZEND_ARG_INFO(1, wireSize)
    ZEND_ARG_INFO(1, dict)
ZEND_END_ARG_INFO()

static zend_function_entry getdns_functions[] = {
    PHP_FE(php_getdns_address, address_svc_args)
    PHP_FE(php_getdns_address_sync, address_svc_sync_args)
    PHP_FE(php_getdns_cancel_callback, cancel_callback_args)
    PHP_FE(php_getdns_context_create, context_create_args)
    PHP_FE(php_getdns_context_destroy, context_only_args)
    PHP_FE(php_getdns_context_detach_eventloop, context_only_args)
    PHP_FE(php_getdns_context_get_api_information, context_only_args)
    PHP_FE(php_getdns_context_get_append_name, context_get_value_args)
    PHP_FE(php_getdns_context_get_dns_root_servers, context_get_value_args)
    PHP_FE(php_getdns_context_get_dns_transport, context_get_value_args)
    PHP_FE(php_getdns_context_get_dnssec_allowed_skew, context_get_value_args)
    PHP_FE(php_getdns_context_get_dnssec_trust_anchors, context_get_value_args)
    PHP_FE(php_getdns_context_get_edns_client_subnet_private, context_get_value_args)
    PHP_FE(php_getdns_context_get_edns_do_bit, context_get_value_args)
    PHP_FE(php_getdns_context_get_edns_extended_rcode, context_get_value_args)
    PHP_FE(php_getdns_context_get_edns_maximum_udp_payload_size, context_get_value_args)
    PHP_FE(php_getdns_context_get_edns_version, context_get_value_args)
    PHP_FE(php_getdns_context_get_follow_redirects, context_get_value_args)
    PHP_FE(php_getdns_context_get_limit_outstanding_queries, context_get_value_args)
    PHP_FE(php_getdns_context_get_namespaces, context_get_value_args)
    PHP_FE(php_getdns_context_get_num_pending_requests, context_only_args)
    PHP_FE(php_getdns_context_get_resolution_type, context_get_value_args)
    PHP_FE(php_getdns_context_get_suffix, context_get_value_args)
    PHP_FE(php_getdns_context_get_timeout, context_get_value_args)
    PHP_FE(php_getdns_context_get_tls_authentication, context_get_value_args)
    PHP_FE(php_getdns_context_get_tls_query_padding_blocksize, context_get_value_args)
    PHP_FE(php_getdns_context_get_update_callback, context_get_update_callback_args)
    PHP_FE(php_getdns_context_get_upstream_recursive_servers, context_get_value_args)
    PHP_FE(php_getdns_context_process_async, context_only_args)
    PHP_FE(php_getdns_context_run, context_only_args)
    PHP_FE(php_getdns_context_set_append_name, context_set_value_args)
    PHP_FE(php_getdns_context_set_dns_root_servers, context_set_value_args)
    PHP_FE(php_getdns_context_set_dns_transport, context_set_value_args)
    PHP_FE(php_getdns_context_set_dns_transport_list, context_set_array_args)
    PHP_FE(php_getdns_context_set_dnssec_allowed_skew, context_set_value_args)
    PHP_FE(php_getdns_context_set_dnssec_trust_anchors, context_set_value_args)
    PHP_FE(php_getdns_context_set_edns_client_subnet_private, context_set_value_args)
    PHP_FE(php_getdns_context_set_edns_do_bit, context_set_value_args)
    PHP_FE(php_getdns_context_set_edns_extended_rcode, context_set_value_args)
    PHP_FE(php_getdns_context_set_edns_maximum_udp_payload_size, context_set_value_args)
    PHP_FE(php_getdns_context_set_edns_version, context_set_value_args)
    PHP_FE(php_getdns_context_set_follow_redirects, context_set_value_args)
    PHP_FE(php_getdns_context_set_idle_timeout, context_set_value_args)
    PHP_FE(php_getdns_context_set_limit_outstanding_queries, context_set_value_args)
    PHP_FE(php_getdns_context_set_namespaces, context_set_array_args)
    PHP_FE(php_getdns_context_set_resolution_type, context_set_value_args)
    PHP_FE(php_getdns_context_set_return_dnssec_status, set_return_dnssec_status_args)
    PHP_FE(php_getdns_context_set_suffix, context_set_value_args)
    PHP_FE(php_getdns_context_set_timeout, context_set_value_args)
    PHP_FE(php_getdns_context_set_tls_authentication, context_set_value_args)
    PHP_FE(php_getdns_context_set_tls_query_padding_blocksize, context_set_value_args)
    PHP_FE(php_getdns_context_set_update_callback, context_set_update_callback_args)
    PHP_FE(php_getdns_context_set_upstream_recursive_servers, context_set_value_args)
    PHP_FE(php_getdns_context_set_use_threads, set_use_threads_args)
    PHP_FE(php_getdns_convert_alabel_to_ulabel, one_string_arg)
    PHP_FE(php_getdns_convert_dns_name_to_fqdn, convert_bindata_string_args)
    PHP_FE(php_getdns_convert_fqdn_to_dns_name, convert_string_bindata_args)
    PHP_FE(php_getdns_convert_ulabel_to_alabel, one_string_arg)
    PHP_FE(php_getdns_dict_create, NULL)
    PHP_FE(php_getdns_dict_create_with_context, context_only_args)
    PHP_FE(php_getdns_dict_destroy, dict_only_args)
    PHP_FE(php_getdns_dict_get_bindata, dict_get_value_args)
    PHP_FE(php_getdns_dict_get_data_type, dict_get_value_args)
    PHP_FE(php_getdns_dict_get_dict, dict_get_value_args)
    PHP_FE(php_getdns_dict_get_int, dict_get_value_args)
    PHP_FE(php_getdns_dict_get_list, dict_get_value_args)
    PHP_FE(php_getdns_dict_get_names, dict_get_names_args)
    PHP_FE(php_getdns_dict_remove_name, dict_remove_args)
    PHP_FE(php_getdns_dict_set_bindata, dict_set_value_args)
    PHP_FE(php_getdns_dict_set_dict, dict_set_value_args)
    PHP_FE(php_getdns_dict_set_int, dict_set_value_args)
    PHP_FE(php_getdns_dict_set_list, dict_set_value_args)
    PHP_FE(php_getdns_dict_util_get_string, dict_get_value_args)
    PHP_FE(php_getdns_dict_util_set_string, dict_set_value_args)
    PHP_FE(php_getdns_display_ip_address, bindata_only_args)
    PHP_FE(php_getdns_fp2rr_list, fp2rr_list_args)
    PHP_FE(php_getdns_general, general_args)
    PHP_FE(php_getdns_general_sync, general_sync_args)
    PHP_FE(php_getdns_get_errorstr_by_id, errorstr_args)
    PHP_FE(php_getdns_get_api_version, NULL)
    PHP_FE(php_getdns_get_api_version_number, NULL)
    PHP_FE(php_getdns_get_version, NULL)
    PHP_FE(php_getdns_get_version_number, NULL)
    PHP_FE(php_getdns_hostname, hostname_args)
    PHP_FE(php_getdns_hostname_sync, hostname_sync_args)
    PHP_FE(php_getdns_list_create, NULL)
    PHP_FE(php_getdns_list_create_with_context, context_only_args)
    PHP_FE(php_getdns_list_destroy, list_only_args)
    PHP_FE(php_getdns_list_get_bindata, list_get_value_args)
    PHP_FE(php_getdns_list_get_data_type, list_get_value_args)
    PHP_FE(php_getdns_list_get_dict, list_get_value_args)
    PHP_FE(php_getdns_list_get_int, list_get_value_args)
    PHP_FE(php_getdns_list_get_length, list_get_length_args)
    PHP_FE(php_getdns_list_get_list, list_get_value_args)
    PHP_FE(php_getdns_list_set_bindata, list_set_value_args)
    PHP_FE(php_getdns_list_set_dict, list_set_value_args)
    PHP_FE(php_getdns_list_set_int, list_set_value_args)
    PHP_FE(php_getdns_list_set_list, list_set_value_args)
    PHP_FE(php_getdns_pretty_print_dict, pretty_print_value_args)
    PHP_FE(php_getdns_pretty_print_list, pretty_print_value_args)
    PHP_FE(php_getdns_print_json_dict, pretty_print_json_value_args)
    PHP_FE(php_getdns_print_json_list, pretty_print_json_value_args)
    PHP_FE(php_getdns_pubkey_pin_create_from_string, pin_create_args)
    PHP_FE(php_getdns_pubkey_pinset_sanity_check, pinset_check_args)
    PHP_FE(php_getdns_root_trust_anchor, date_time_args)
    PHP_FE(php_getdns_rr_dict2str, dict2str_args)
    PHP_FE(php_getdns_rr_dict2str_buf, dict2strlen_args)
    PHP_FE(php_getdns_rr_dict2str_scan, dict2strlen_args)
    PHP_FE(php_getdns_rr_dict2wire, dict2wire_args)
    PHP_FE(php_getdns_rr_dict2wire_buf, dict2wire_args)
    PHP_FE(php_getdns_rr_dict2wire_scan, dict2wire_args)
    PHP_FE(php_getdns_service, address_svc_args)
    PHP_FE(php_getdns_service_sync, address_svc_sync_args)
    PHP_FE(php_getdns_str2rr_dict, str2rr_args)
    PHP_FE(php_getdns_util_convert_array, util_convert_array_args)
    PHP_FE(php_getdns_util_convert_dict, util_convert_dict_args)
    PHP_FE(php_getdns_util_convert_list, util_convert_list_args)
    PHP_FE(php_getdns_validate_dnssec, validate_dnssec_args)
    PHP_FE(php_getdns_wire2rr_dict, wire2rr_dict_args)
    PHP_FE(php_getdns_wire2rr_dict_buf, wire2rr_dict_buf_args)
    PHP_FE(php_getdns_wire2rr_dict_scan, wire2rr_dict_scan_args)
    {NULL, NULL, NULL}
};

zend_module_entry getdns_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_GETDNS_EXTNAME,
    getdns_functions,
    PHP_MINIT(getdns),
    PHP_MSHUTDOWN(getdns),
    PHP_RINIT(getdns),
    PHP_RSHUTDOWN(getdns),
    PHP_MINFO(getdns),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_GETDNS_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_GETDNS
ZEND_GET_MODULE(getdns)
#endif
    PHP_INI_BEGIN()
    PHP_INI_END()

static void php_getdns_init_globals(zend_getdns_globals * getdns_globals)
{
    /* This is just a place holder for any globals that might need to be defined. */
    getdns_globals->getdnsTestGlobal = 42;
}

PHP_RINIT_FUNCTION(getdns)
{
    zval *respStr;

    /* String constants MUST reside in Zend's internal memory. Allocate a zval for them. */
    MAKE_STD_ZVAL(respStr);

    /* Register a global variable for test purposes. */
    GETDNS_G(getdnsTestGlobal) = 42;

    /* Register return values. */
    REGISTER_LONG_CONSTANT("GETDNS_RETURN_GOOD", GETDNS_RETURN_GOOD,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_GOOD_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_GOOD_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_GENERIC_ERROR",
			   GETDNS_RETURN_GENERIC_ERROR, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_GENERIC_ERROR_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_GENERIC_ERROR_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_BAD_DOMAIN_NAME",
			   GETDNS_RETURN_BAD_DOMAIN_NAME, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_BAD_DOMAIN_NAME_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_BAD_DOMAIN_NAME_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_BAD_CONTEXT",
			   GETDNS_RETURN_BAD_CONTEXT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_BAD_CONTEXT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_BAD_CONTEXT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_CONTEXT_UPDATE_FAIL",
			   GETDNS_RETURN_CONTEXT_UPDATE_FAIL, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_CONTEXT_UPDATE_FAIL_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_CONTEXT_UPDATE_FAIL_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_UNKNOWN_TRANSACTION",
			   GETDNS_RETURN_UNKNOWN_TRANSACTION, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_UNKNOWN_TRANSACTION_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_UNKNOWN_TRANSACTION_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_NO_SUCH_LIST_ITEM",
			   GETDNS_RETURN_NO_SUCH_LIST_ITEM, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_NO_SUCH_LIST_ITEM_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_NO_SUCH_LIST_ITEM_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_NO_SUCH_DICT_NAME",
			   GETDNS_RETURN_NO_SUCH_DICT_NAME, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_NO_SUCH_DICT_NAME_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_NO_SUCH_DICT_NAME_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_WRONG_TYPE_REQUESTED",
			   GETDNS_RETURN_WRONG_TYPE_REQUESTED, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_WRONG_TYPE_REQUESTED_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_WRONG_TYPE_REQUESTED_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_NO_SUCH_EXTENSION",
			   GETDNS_RETURN_NO_SUCH_EXTENSION, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_NO_SUCH_EXTENSION_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_NO_SUCH_EXTENSION_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_EXTENSION_MISFORMAT",
			   GETDNS_RETURN_EXTENSION_MISFORMAT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_EXTENSION_MISFORMAT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_EXTENSION_MISFORMAT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_DNSSEC_WITH_STUB_DISALLOWED",
			   GETDNS_RETURN_DNSSEC_WITH_STUB_DISALLOWED,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_DNSSEC_WITH_STUB_DISALLOWED_TEXT,
		1);
    REGISTER_STRING_CONSTANT
	("GETDNS_RETURN_DNSSEC_WITH_STUB_DISALLOWED_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_MEMORY_ERROR",
			   GETDNS_RETURN_MEMORY_ERROR, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_MEMORY_ERROR_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_MEMORY_ERROR_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_INVALID_PARAMETER",
			   GETDNS_RETURN_INVALID_PARAMETER, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_INVALID_PARAMETER_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_INVALID_PARAMETER_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_NOT_IMPLEMENTED",
			   GETDNS_RETURN_NOT_IMPLEMENTED, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_NOT_IMPLEMENTED_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_NOT_IMPLEMENTED_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RETURN_NEED_MORE_SPACE",
			   GETDNS_RETURN_NEED_MORE_SPACE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RETURN_NEED_MORE_SPACE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RETURN_NEED_MORE_SPACE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_AUTHENTICATION_NONE",
			   GETDNS_AUTHENTICATION_NONE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_AUTHENTICATION_NONE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_AUTHENTICATION_NONE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Note that GETDNS_AUTHENTICATION_HOSTNAME is an alias for
       GETDNS_AUTHENTICATION_REQUIRED. */
    REGISTER_LONG_CONSTANT("GETDNS_AUTHENTICATION_HOSTNAME",
			   GETDNS_AUTHENTICATION_HOSTNAME, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_AUTHENTICATION_REQUIRED",
			   GETDNS_AUTHENTICATION_REQUIRED, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_AUTHENTICATION_REQUIRED_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_AUTHENTICATION_REQUIRED_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register response status codes. */

    REGISTER_LONG_CONSTANT("GETDNS_RESPSTATUS_GOOD",
			   GETDNS_RESPSTATUS_GOOD, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESPSTATUS_GOOD_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESPSTATUS_GOOD_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RESPSTATUS_NO_NAME",
			   GETDNS_RESPSTATUS_NO_NAME, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESPSTATUS_NO_NAME_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESPSTATUS_NO_NAME_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RESPSTATUS_ALL_TIMEOUT",
			   GETDNS_RESPSTATUS_ALL_TIMEOUT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESPSTATUS_ALL_TIMEOUT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESPSTATUS_ALL_TIMEOUT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RESPSTATUS_NO_SECURE_ANSWERS",
			   GETDNS_RESPSTATUS_NO_SECURE_ANSWERS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESPSTATUS_NO_SECURE_ANSWERS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESPSTATUS_NO_SECURE_ANSWERS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RESPSTATUS_ALL_BOGUS_ANSWERS",
			   GETDNS_RESPSTATUS_ALL_BOGUS_ANSWERS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESPSTATUS_ALL_BOGUS_ANSWERS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESPSTATUS_ALL_BOGUS_ANSWERS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register DNSSEC values. */

    REGISTER_LONG_CONSTANT("GETDNS_DNSSEC_SECURE", GETDNS_DNSSEC_SECURE,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_DNSSEC_SECURE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_DNSSEC_SECURE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_DNSSEC_BOGUS", GETDNS_DNSSEC_BOGUS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_DNSSEC_BOGUS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_DNSSEC_BOGUS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_DNSSEC_INDETERMINATE",
			   GETDNS_DNSSEC_INDETERMINATE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_DNSSEC_INDETERMINATE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_DNSSEC_INDETERMINATE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_DNSSEC_INSECURE",
			   GETDNS_DNSSEC_INSECURE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_DNSSEC_INSECURE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_DNSSEC_INSECURE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_DNSSEC_NOT_PERFORMED",
			   GETDNS_DNSSEC_NOT_PERFORMED, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_DNSSEC_NOT_PERFORMED_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_DNSSEC_NOT_PERFORMED_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register namespace types. */

    REGISTER_LONG_CONSTANT("GETDNS_NAMESPACE_DNS", GETDNS_NAMESPACE_DNS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMESPACE_DNS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMESPACE_DNS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_NAMESPACE_LOCALNAMES",
			   GETDNS_NAMESPACE_LOCALNAMES, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMESPACE_LOCALNAMES_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMESPACE_LOCALNAMES_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_NAMESPACE_NETBIOS",
			   GETDNS_NAMESPACE_NETBIOS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMESPACE_NETBIOS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMESPACE_NETBIOS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_NAMESPACE_MDNS", GETDNS_NAMESPACE_MDNS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMESPACE_MDNS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMESPACE_MDNS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_NAMESPACE_NIS", GETDNS_NAMESPACE_NIS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMESPACE_NIS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMESPACE_NIS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register resolution types. */

    REGISTER_LONG_CONSTANT("GETDNS_RESOLUTION_STUB",
			   GETDNS_RESOLUTION_STUB, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESOLUTION_STUB_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESOLUTION_STUB_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_RESOLUTION_RECURSING",
			   GETDNS_RESOLUTION_RECURSING, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_RESOLUTION_RECURSING_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_RESOLUTION_RECURSING_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register redirect policies. */

    REGISTER_LONG_CONSTANT("GETDNS_REDIRECTS_FOLLOW",
			   GETDNS_REDIRECTS_FOLLOW, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_REDIRECTS_FOLLOW_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_REDIRECTS_FOLLOW_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_REDIRECTS_DO_NOT_FOLLOW",
			   GETDNS_REDIRECTS_DO_NOT_FOLLOW, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_REDIRECTS_DO_NOT_FOLLOW_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_REDIRECTS_DO_NOT_FOLLOW_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register transport arrangements. */

    REGISTER_LONG_CONSTANT
	("GETDNS_TRANSPORT_UDP_FIRST_AND_FALL_BACK_TO_TCP",
	 GETDNS_TRANSPORT_UDP_FIRST_AND_FALL_BACK_TO_TCP, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_TRANSPORT_UDP_FIRST_AND_FALL_BACK_TO_TCP_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_TRANSPORT_UDP_FIRST_AND_FALL_BACK_TO_TCP_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_TRANSPORT_UDP_ONLY",
			   GETDNS_TRANSPORT_UDP_ONLY, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_TRANSPORT_UDP_ONLY_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_TRANSPORT_UDP_ONLY_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_TRANSPORT_TCP_ONLY",
			   GETDNS_TRANSPORT_TCP_ONLY, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_TRANSPORT_TCP_ONLY_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_TRANSPORT_TCP_ONLY_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_TRANSPORT_TCP_ONLY_KEEP_CONNECTIONS_OPEN",
	 GETDNS_TRANSPORT_TCP_ONLY_KEEP_CONNECTIONS_OPEN, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_TRANSPORT_TCP_ONLY_KEEP_CONNECTIONS_OPEN_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_TRANSPORT_TCP_ONLY_KEEP_CONNECTIONS_OPEN_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_TRANSPORT_TLS_ONLY_KEEP_CONNECTIONS_OPEN",
	 GETDNS_TRANSPORT_TLS_ONLY_KEEP_CONNECTIONS_OPEN, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_TRANSPORT_TLS_ONLY_KEEP_CONNECTIONS_OPEN_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_TRANSPORT_TLS_ONLY_KEEP_CONNECTIONS_OPEN_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_TRANSPORT_TLS_FIRST_AND_FALL_BACK_TO_TCP_KEEP_CONNECTIONS_OPEN",
	 GETDNS_TRANSPORT_TLS_FIRST_AND_FALL_BACK_TO_TCP_KEEP_CONNECTIONS_OPEN, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_TRANSPORT_TLS_FIRST_AND_FALL_BACK_TO_TCP_KEEP_CONNECTIONS_OPEN_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_TRANSPORT_TLS_FIRST_AND_FALL_BACK_TO_TCP_KEEP_CONNECTIONS_OPEN_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    /* Register base transports for use in transport list. */

    REGISTER_LONG_CONSTANT("GETDNS_TRANSPORT_UDP", GETDNS_TRANSPORT_UDP, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_TRANSPORT_UDP_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_TRANSPORT_UDP_TEXT", Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_TRANSPORT_TCP", GETDNS_TRANSPORT_TCP, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_TRANSPORT_TCP_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_TRANSPORT_TCP_TEXT", Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_TRANSPORT_TLS", GETDNS_TRANSPORT_TLS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_TRANSPORT_TLS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_TRANSPORT_TLS_TEXT", Z_STRVAL_P(respStr), CONST_CS);

    /* Register suffix appending methods. */

    REGISTER_LONG_CONSTANT("GETDNS_APPEND_NAME_ALWAYS",
			   GETDNS_APPEND_NAME_ALWAYS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_APPEND_NAME_ALWAYS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_APPEND_NAME_ALWAYS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_APPEND_NAME_ONLY_TO_SINGLE_LABEL_AFTER_FAILURE",
	 GETDNS_APPEND_NAME_ONLY_TO_SINGLE_LABEL_AFTER_FAILURE, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_APPEND_NAME_ONLY_TO_SINGLE_LABEL_AFTER_FAILURE_TEXT,
		1);
    REGISTER_STRING_CONSTANT
	("GETDNS_APPEND_NAME_ONLY_TO_SINGLE_LABEL_AFTER_FAILURE_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_APPEND_NAME_ONLY_TO_MULTIPLE_LABEL_NAME_AFTER_FAILURE",
	 GETDNS_APPEND_NAME_ONLY_TO_MULTIPLE_LABEL_NAME_AFTER_FAILURE,
	 CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_APPEND_NAME_ONLY_TO_MULTIPLE_LABEL_NAME_AFTER_FAILURE_TEXT,
		1);
    REGISTER_STRING_CONSTANT
	("GETDNS_APPEND_NAME_ONLY_TO_MULTIPLE_LABEL_NAME_AFTER_FAILURE_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_APPEND_NAME_NEVER",
			   GETDNS_APPEND_NAME_NEVER, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_APPEND_NAME_NEVER_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_APPEND_NAME_NEVER_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register context codes. */

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_NAMESPACES",
			   GETDNS_CONTEXT_CODE_NAMESPACES, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_NAMESPACES_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_NAMESPACES_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_RESOLUTION_TYPE",
			   GETDNS_CONTEXT_CODE_RESOLUTION_TYPE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_RESOLUTION_TYPE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_RESOLUTION_TYPE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_FOLLOW_REDIRECTS",
			   GETDNS_CONTEXT_CODE_FOLLOW_REDIRECTS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_FOLLOW_REDIRECTS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_FOLLOW_REDIRECTS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_CONTEXT_CODE_UPSTREAM_RECURSIVE_SERVERS",
	 GETDNS_CONTEXT_CODE_UPSTREAM_RECURSIVE_SERVERS, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_CONTEXT_CODE_UPSTREAM_RECURSIVE_SERVERS_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_UPSTREAM_RECURSIVE_SERVERS_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_DNS_ROOT_SERVERS",
			   GETDNS_CONTEXT_CODE_DNS_ROOT_SERVERS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_DNS_ROOT_SERVERS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_DNS_ROOT_SERVERS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_DNS_TRANSPORT",
			   GETDNS_CONTEXT_CODE_DNS_TRANSPORT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_DNS_TRANSPORT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_DNS_TRANSPORT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_LIMIT_OUTSTANDING_QUERIES",
			   GETDNS_CONTEXT_CODE_LIMIT_OUTSTANDING_QUERIES,
			   CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_CONTEXT_CODE_LIMIT_OUTSTANDING_QUERIES_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_LIMIT_OUTSTANDING_QUERIES_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_APPEND_NAME",
			   GETDNS_CONTEXT_CODE_APPEND_NAME, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_APPEND_NAME_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_APPEND_NAME_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_SUFFIX",
			   GETDNS_CONTEXT_CODE_SUFFIX, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_SUFFIX_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_SUFFIX_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_DNSSEC_TRUST_ANCHORS",
			   GETDNS_CONTEXT_CODE_DNSSEC_TRUST_ANCHORS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_DNSSEC_TRUST_ANCHORS_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_DNSSEC_TRUST_ANCHORS_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT
	("GETDNS_CONTEXT_CODE_EDNS_MAXIMUM_UDP_PAYLOAD_SIZE",
	 GETDNS_CONTEXT_CODE_EDNS_MAXIMUM_UDP_PAYLOAD_SIZE, CONST_CS);
    ZVAL_STRING(respStr,
		GETDNS_CONTEXT_CODE_EDNS_MAXIMUM_UDP_PAYLOAD_SIZE_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_EDNS_MAXIMUM_UDP_PAYLOAD_SIZE_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_EXTENDED_RCODE",
			   GETDNS_CONTEXT_CODE_EDNS_EXTENDED_RCODE,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_EDNS_EXTENDED_RCODE_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_EDNS_EXTENDED_RCODE_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_VERSION",
			   GETDNS_CONTEXT_CODE_EDNS_VERSION, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_EDNS_VERSION_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_VERSION_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_DO_BIT",
			   GETDNS_CONTEXT_CODE_EDNS_DO_BIT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_EDNS_DO_BIT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_DO_BIT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_DNSSEC_ALLOWED_SKEW",
			   GETDNS_CONTEXT_CODE_DNSSEC_ALLOWED_SKEW,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_DNSSEC_ALLOWED_SKEW_TEXT, 1);
    REGISTER_STRING_CONSTANT
	("GETDNS_CONTEXT_CODE_DNSSEC_ALLOWED_SKEW_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_MEMORY_FUNCTIONS",
			   GETDNS_CONTEXT_CODE_MEMORY_FUNCTIONS, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_MEMORY_FUNCTIONS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_MEMORY_FUNCTIONS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_TIMEOUT",
			   GETDNS_CONTEXT_CODE_TIMEOUT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_TIMEOUT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_TIMEOUT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_IDLE_TIMEOUT",
			   GETDNS_CONTEXT_CODE_IDLE_TIMEOUT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_IDLE_TIMEOUT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_IDLE_TIMEOUT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_TLS_AUTHENTICATION",
			   GETDNS_CONTEXT_CODE_TLS_AUTHENTICATION, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_TLS_AUTHENTICATION_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_TLS_AUTHENTICATION_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_CLIENT_SUBNET_PRIVATE",
			   GETDNS_CONTEXT_CODE_EDNS_CLIENT_SUBNET_PRIVATE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_EDNS_CLIENT_SUBNET_PRIVATE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_EDNS_CLIENT_SUBNET_PRIVATE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_TLS_QUERY_PADDING_BLOCKSIZE",
			   GETDNS_CONTEXT_CODE_TLS_QUERY_PADDING_BLOCKSIZE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_TLS_QUERY_PADDING_BLOCKSIZE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_TLS_QUERY_PADDING_BLOCKSIZE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CONTEXT_CODE_PUBKEY_PINSET",
			   GETDNS_CONTEXT_CODE_PUBKEY_PINSET, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CONTEXT_CODE_PUBKEY_PINSET_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CONTEXT_CODE_PUBKEY_PINSET_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register callback types. */

    REGISTER_LONG_CONSTANT("GETDNS_CALLBACK_COMPLETE",
			   GETDNS_CALLBACK_COMPLETE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CALLBACK_COMPLETE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CALLBACK_COMPLETE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CALLBACK_CANCEL",
			   GETDNS_CALLBACK_CANCEL, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CALLBACK_CANCEL_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CALLBACK_CANCEL_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CALLBACK_TIMEOUT",
			   GETDNS_CALLBACK_TIMEOUT, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CALLBACK_TIMEOUT_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CALLBACK_TIMEOUT_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_CALLBACK_ERROR", GETDNS_CALLBACK_ERROR,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_CALLBACK_ERROR_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_CALLBACK_ERROR_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register name service types. */

    REGISTER_LONG_CONSTANT("GETDNS_NAMETYPE_DNS", GETDNS_NAMETYPE_DNS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMETYPE_DNS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMETYPE_DNS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_NAMETYPE_WINS", GETDNS_NAMETYPE_WINS,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_NAMETYPE_WINS_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_NAMETYPE_WINS_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register extension values. */

    REGISTER_LONG_CONSTANT("GETDNS_EXTENSION_TRUE", GETDNS_EXTENSION_TRUE,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_EXTENSION_TRUE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_EXTENSION_TRUE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_EXTENSION_FALSE",
			   GETDNS_EXTENSION_FALSE, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_EXTENSION_FALSE_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_EXTENSION_FALSE_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    /* Register DNS error values. */

    REGISTER_LONG_CONSTANT("GETDNS_BAD_DNS_CNAME_IN_TARGET",
			   GETDNS_BAD_DNS_CNAME_IN_TARGET, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_BAD_DNS_CNAME_IN_TARGET_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_BAD_DNS_CNAME_IN_TARGET_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_BAD_DNS_ALL_NUMERIC_LABEL",
			   GETDNS_BAD_DNS_ALL_NUMERIC_LABEL, CONST_CS);
    ZVAL_STRING(respStr, GETDNS_BAD_DNS_ALL_NUMERIC_LABEL_TEXT, 1);
    REGISTER_STRING_CONSTANT("GETDNS_BAD_DNS_ALL_NUMERIC_LABEL_TEXT",
			     Z_STRVAL_P(respStr), CONST_CS);

    REGISTER_LONG_CONSTANT("GETDNS_BAD_DNS_CNAME_RETURNED_FOR_OTHER_TYPE",
			   GETDNS_BAD_DNS_CNAME_RETURNED_FOR_OTHER_TYPE,
			   CONST_CS);
    ZVAL_STRING(respStr, GETDNS_BAD_DNS_CNAME_RETURNED_FOR_OTHER_TYPE_TEXT,
		1);
    REGISTER_STRING_CONSTANT
	("GETDNS_BAD_DNS_CNAME_RETURNED_FOR_OTHER_TYPE_TEXT",
	 Z_STRVAL_P(respStr), CONST_CS);

    /* Register RRTYPEs. */

    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_A", GETDNS_RRTYPE_A, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NS", GETDNS_RRTYPE_NS, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MD", GETDNS_RRTYPE_MD, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MF", GETDNS_RRTYPE_MF, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CNAME", GETDNS_RRTYPE_CNAME,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SOA", GETDNS_RRTYPE_SOA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MB", GETDNS_RRTYPE_MB, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MG", GETDNS_RRTYPE_MG, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MR", GETDNS_RRTYPE_MR, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NULL", GETDNS_RRTYPE_NULL,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_WKS", GETDNS_RRTYPE_WKS,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_PTR", GETDNS_RRTYPE_PTR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_HINFO", GETDNS_RRTYPE_HINFO,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MINFO", GETDNS_RRTYPE_MINFO,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MX", GETDNS_RRTYPE_MX, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TXT", GETDNS_RRTYPE_TXT,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_RP", GETDNS_RRTYPE_RP, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_AFSDB", GETDNS_RRTYPE_AFSDB,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_X25", GETDNS_RRTYPE_X25,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_ISDN", GETDNS_RRTYPE_ISDN,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_RT", GETDNS_RRTYPE_RT, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NSAP", GETDNS_RRTYPE_NSAP,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SIG", GETDNS_RRTYPE_SIG,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_KEY", GETDNS_RRTYPE_KEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_PX", GETDNS_RRTYPE_PX, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_GPOS", GETDNS_RRTYPE_A,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_AAAA", GETDNS_RRTYPE_AAAA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_LOC", GETDNS_RRTYPE_LOC,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NXT", GETDNS_RRTYPE_NXT,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_EID", GETDNS_RRTYPE_EID,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NIMLOC", GETDNS_RRTYPE_NIMLOC,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SRV", GETDNS_RRTYPE_SRV,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_ATMA", GETDNS_RRTYPE_ATMA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NAPTR", GETDNS_RRTYPE_NAPTR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_KX", GETDNS_RRTYPE_KX, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CERT", GETDNS_RRTYPE_CERT,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_A6", GETDNS_RRTYPE_A6, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_DNAME", GETDNS_RRTYPE_DNAME,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SINK", GETDNS_RRTYPE_SINK,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_OPT", GETDNS_RRTYPE_OPT,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_APL", GETDNS_RRTYPE_APL,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_DS", GETDNS_RRTYPE_DS, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SSHFP", GETDNS_RRTYPE_SSHFP,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_IPSECKEY",
			   GETDNS_RRTYPE_IPSECKEY, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_RRSIG", GETDNS_RRTYPE_RRSIG,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NSEC", GETDNS_RRTYPE_NSEC,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_DNSKEY", GETDNS_RRTYPE_DNSKEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_DHCID", GETDNS_RRTYPE_DHCID,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NSEC3", GETDNS_RRTYPE_NSEC3,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NSEC3PARAM",
			   GETDNS_RRTYPE_NSEC3PARAM, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TLSA", GETDNS_RRTYPE_TLSA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_HIP", GETDNS_RRTYPE_HIP,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NINFO", GETDNS_RRTYPE_NINFO,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_RKEY", GETDNS_RRTYPE_RKEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TALINK", GETDNS_RRTYPE_TALINK,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CDS", GETDNS_RRTYPE_CDS,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CDNSKEY", GETDNS_RRTYPE_CDNSKEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_OPENPGPKEY",
			   GETDNS_RRTYPE_OPENPGPKEY, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CSYNC",
			   GETDNS_RRTYPE_CSYNC, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_SPF", GETDNS_RRTYPE_SPF,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_UINFO", GETDNS_RRTYPE_UINFO,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_UID", GETDNS_RRTYPE_UID,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_GID", GETDNS_RRTYPE_GID,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_UNSPEC", GETDNS_RRTYPE_UNSPEC,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_NID", GETDNS_RRTYPE_NID,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_L32", GETDNS_RRTYPE_L32,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_L64", GETDNS_RRTYPE_L64,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_LP", GETDNS_RRTYPE_LP, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_EUI48", GETDNS_RRTYPE_EUI48,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_EUI64", GETDNS_RRTYPE_EUI64,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TKEY", GETDNS_RRTYPE_TKEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TSIG", GETDNS_RRTYPE_TSIG,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_IXFR", GETDNS_RRTYPE_IXFR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_AXFR", GETDNS_RRTYPE_AXFR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MAILB", GETDNS_RRTYPE_MAILB,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_MAILA", GETDNS_RRTYPE_MAILA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_ANY", GETDNS_RRTYPE_ANY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_URI", GETDNS_RRTYPE_URI,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_CAA", GETDNS_RRTYPE_CAA,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_TA", GETDNS_RRTYPE_TA, CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRTYPE_DLV", GETDNS_RRTYPE_DLV,
			   CONST_CS);

    /* Register RRCLASSes. */

    REGISTER_LONG_CONSTANT("GETDNS_RRCLASS_IN", GETDNS_RRCLASS_IN,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRCLASS_CH", GETDNS_RRCLASS_CH,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRCLASS_HS", GETDNS_RRCLASS_HS,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRCLASS_NONE", GETDNS_RRCLASS_NONE,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RRCLASS_ANY", GETDNS_RRCLASS_ANY,
			   CONST_CS);

    /* Register OPCODEs. */

    REGISTER_LONG_CONSTANT("GETDNS_OPCODE_QUERY", GETDNS_OPCODE_QUERY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_OPCODE_IQUERY", GETDNS_OPCODE_IQUERY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_OPCODE_STATUS", GETDNS_OPCODE_STATUS,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_OPCODE_NOTIFY", GETDNS_OPCODE_NOTIFY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_OPCODE_UPDATE", GETDNS_OPCODE_UPDATE,
			   CONST_CS);

    /* Register RCODEs. */

    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NOERROR", GETDNS_RCODE_NOERROR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_FORMERR", GETDNS_RCODE_FORMERR,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_SERVFAIL", GETDNS_RCODE_SERVFAIL,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NXDOMAIN", GETDNS_RCODE_NXDOMAIN,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NOTIMP", GETDNS_RCODE_NOTIMP,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_REFUSED", GETDNS_RCODE_REFUSED,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_YXDOMAIN", GETDNS_RCODE_YXDOMAIN,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_YXRRSET", GETDNS_RCODE_YXRRSET,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NXRRSET", GETDNS_RCODE_NXRRSET,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NOTAUTH", GETDNS_RCODE_NOTAUTH,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_NOTZONE", GETDNS_RCODE_NOTZONE,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADVERS", GETDNS_RCODE_BADVERS,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADSIG", GETDNS_RCODE_BADSIG,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADKEY", GETDNS_RCODE_BADKEY,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADTIME", GETDNS_RCODE_BADTIME,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADMODE", GETDNS_RCODE_BADMODE,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADNAME", GETDNS_RCODE_BADNAME,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADALG", GETDNS_RCODE_BADALG,
			   CONST_CS);
    REGISTER_LONG_CONSTANT("GETDNS_RCODE_BADTRUNC", GETDNS_RCODE_BADTRUNC,
			   CONST_CS);

    /* Register enumerated data types. */

    REGISTER_LONG_CONSTANT("t_dict", t_dict, CONST_CS);
    REGISTER_LONG_CONSTANT("t_list", t_list, CONST_CS);
    REGISTER_LONG_CONSTANT("t_int", t_int, CONST_CS);
    REGISTER_LONG_CONSTANT("t_bindata", t_bindata, CONST_CS);

    /* All done! */
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(getdns)
{
    return SUCCESS;
}

PHP_MINIT_FUNCTION(getdns)
{
    ZEND_INIT_MODULE_GLOBALS(getdns, php_getdns_init_globals, NULL);
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(getdns)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MINFO_FUNCTION(getdns)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Extension for the getdns Library", "enabled");
    php_info_print_table_row(2, "Extension Version", PHP_GETDNS_VERSION);
    php_info_print_table_row(2, "Compatible getdns Library Version", GETDNS_VERSION);
    php_info_print_table_row(2, "Compatible getdns API Version", GETDNS_API_VERSION);
    php_info_print_table_row(2, "Extension Author",
			     "Scott Hollenbeck <shollenbeck@verisign.com>");
    php_info_print_table_end();
    DISPLAY_INI_ENTRIES();
}

/**
 * Callback function for context update processing.
 */
void context_update_callback(getdns_context *context,
			     getdns_context_code_t changedValue,
			     void *userArg)
{
    int phpResult = 0;
    zval *clientArgs[2], *userArgs, **hashData;
    zval funcName, retVal;
    char *phpCallback = NULL;
    HashTable *arrayHash;
    HashPosition hashPtr;

    /*
     * Set up PHP function arguments and call the function in PHP
     * user space.
     * Note that userArg is a PHP array. The first element of the
     * array contains the name of the user space callback function.
     * Additional elements can contain whatever the client wants
     * to have passed to the callback function.
     */
    userArgs = (zval *) userArg;
    arrayHash = Z_ARRVAL_P(userArgs);
    zend_hash_internal_pointer_reset_ex(arrayHash, &hashPtr);
    if (zend_hash_get_current_data_ex(arrayHash, (void**) &hashData, &hashPtr) == SUCCESS) {
        phpCallback = (char *) Z_STRVAL_PP(hashData);
    }
    else {
        php_error_docref(NULL TSRMLS_DC, E_WARNING, "Invalid callback parameters!");
	return;
    }

    /*
     * Create zvals for parameters.
     * No need for userArgs since they're just pass-through here.
     */
    ZVAL_STRING(&funcName, phpCallback, 1);
    MAKE_STD_ZVAL(clientArgs[0]);
    ZVAL_LONG(clientArgs[0], (long) changedValue);
    clientArgs[1] = userArgs;

    phpResult = call_user_function(EG(function_table), NULL,
                   &funcName, &retVal, 2, clientArgs TSRMLS_DC);
    if (phpResult == FAILURE) {
        php_error_docref(NULL TSRMLS_DC, E_WARNING, "Callback failed!");
    }

    zval_dtor(&funcName);
    zval_dtor(clientArgs[0]);
}

/**
 * Callback function for asynchronous processing.
 */
void async_callback(getdns_context *context,
		    getdns_callback_type_t callbackType,
		    getdns_dict *response,
		    void *userArg,
		    getdns_transaction_t transID)
{
    int phpResult = 0;
    zval *clientArgs[4], *userArgs, **hashData;
    zval funcName, retVal;
    char *phpCallback = NULL;
    HashTable *arrayHash;
    HashPosition hashPtr;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;
    char *transIDStr = NULL;

    /*
     * Set up PHP function arguments and call the function in PHP
     * user space.
     * Note that userArg is a PHP array. The first element of the
     * array contains the name of the user space callback function.
     * Additional elements can contain whatever the client wants
     * to have passed to the callback function.
     */
    userArgs = (zval *) userArg;
    arrayHash = Z_ARRVAL_P(userArgs);
    zend_hash_internal_pointer_reset_ex(arrayHash, &hashPtr);
    if (zend_hash_get_current_data_ex(arrayHash, (void**) &hashData, &hashPtr) == SUCCESS) {
        phpCallback = (char *) Z_STRVAL_PP(hashData);
    }
    else {
        php_error_docref(NULL TSRMLS_DC, E_WARNING, "Invalid callback parameters!");
	return;
    }

    /*
     * Create zvals for parameters.
     * No need for userArgs since they're just pass-through here.
     */
    ZVAL_STRING(&funcName, phpCallback, 1);
    MAKE_STD_ZVAL(clientArgs[0]);
    ZVAL_LONG(clientArgs[0], (long) response);
    MAKE_STD_ZVAL(clientArgs[1]);
    ZVAL_LONG(clientArgs[1], callbackType);
    clientArgs[2] = userArgs;
    MAKE_STD_ZVAL(clientArgs[3]);
    transIDStr = (char *) malloc(transIDSize + 1);
    if (transIDStr) {
        transIDStr[transIDSize] = 0;
        snprintf(transIDStr, transIDSize + 1, "%016llX", (unsigned long long) transID);
        ZVAL_STRINGL(clientArgs[3], transIDStr, transIDSize, 1);
        free(transIDStr);
        phpResult = call_user_function(EG(function_table), NULL,
                   &funcName, &retVal, 4, clientArgs TSRMLS_DC);
        if (phpResult == FAILURE) {
            php_error_docref(NULL TSRMLS_DC, E_WARNING, "Callback failed!");
        }
    }
    else {
        php_error_docref(NULL TSRMLS_DC, E_WARNING, "Callback failed; memory error!");
    }

    zval_dtor(&funcName);
    zval_dtor(clientArgs[0]);
    zval_dtor(clientArgs[1]);
    zval_dtor(clientArgs[3]);
}

/**
 * Function to asynchronously resolve a name and return an address.
 */
PHP_FUNCTION(php_getdns_address)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpExtensions = 0;
    char *name = NULL;
    size_t nameLen = 0;
    zval *phpUserArg = NULL, *phpTrans = NULL;
    getdns_dict *extensions = NULL;
    void *userArg = NULL;
    getdns_transaction_t trans = 0, *transPtr = NULL;
    char *endPtr = NULL, *transIDStr = NULL, *transStr = NULL;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lslzz", &phpContext, &name, &nameLen,
	 &phpExtensions, &phpUserArg, &phpTrans) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpUserArg) == IS_ARRAY) {
        userArg = (void *) phpUserArg;
    }
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    switch (Z_TYPE_P(phpTrans)) {
        case IS_NULL:
	    transPtr = NULL;
	    break;
	case IS_STRING:
	    transStr = Z_STRVAL_P(phpTrans);
	    endPtr = NULL;

	    trans = (uint64_t) strtoull(transStr, &endPtr, 16);
            transPtr = &trans;
	    break;
        default:
	    RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_address(context, name, extensions,
                            userArg, transPtr,
			    async_callback);

    /* Return the transaction identifier and the result. */
    if (transPtr) {
        convert_to_null(phpTrans);
        transIDStr = (char *) malloc(transIDSize + 1);
        if (transIDStr) {
	    transIDStr[transIDSize] = 0;
            snprintf(transIDStr, transIDSize + 1, "%016llX", (unsigned long long) trans);
            ZVAL_STRINGL(phpTrans, transIDStr, transIDSize, 1);
            free(transIDStr);
        }
    }
    RETURN_LONG((long) result);
}

/**
 * Function to synchronously resolve a name and return an address.
 */
PHP_FUNCTION(php_getdns_address_sync)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpExtensions = 0;
    zval *phpOut = NULL;
    char *name = NULL;
    size_t nameLen = 0;
    getdns_dict *extensions = NULL, *response = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lslz", &phpContext, &name, &nameLen,
	 &phpExtensions, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_address_sync(context, name, extensions, &response);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) response);
    RETURN_LONG((long) result);
}

/**
 * Function to cancel a callback.
 */
PHP_FUNCTION(php_getdns_cancel_callback)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0;
    zval *phpTransID = NULL;
    getdns_transaction_t transID = 0;
    char *transIDStr = NULL;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext,
	 &phpTransID) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpTransID) == IS_STRING) {
	char *transStr = Z_STRVAL_P(phpTransID);
	char *endPtr = NULL;

	transID = (uint64_t) strtoull(transStr, &endPtr, 16);
    }   
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_cancel_callback(context, transID);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to create and return a context.
 */
PHP_FUNCTION(php_getdns_context_create)
{
    zval *phpOut = NULL;
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    zend_bool phpSetFromOS = 0;
    int setFromOS = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zb", &phpOut, &phpSetFromOS)
	== FAILURE) {
	RETURN_NULL();
    }
    setFromOS = (int) phpSetFromOS;
    result = getdns_context_create(&context, setFromOS);

    /* Store the context value and return the result. */
    convert_to_long(phpOut);
    ZVAL_LONG(phpOut, (long) context);
    RETURN_LONG((long) result);
}

/**
 * Function to destroy a context.
 */
PHP_FUNCTION(php_getdns_context_destroy)
{
    struct getdns_context *context = NULL;
    long phpContext;

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpContext)
	== FAILURE) {
	RETURN_NULL();
    }
    context = (getdns_context *) phpContext;
    getdns_context_destroy(context);
}

/**
 * Function to retrieve a dictionary containing API information from a context.
 */
PHP_FUNCTION(php_getdns_context_get_api_information)
{
    long phpPtr = 0;
    getdns_dict *dict = NULL;
    getdns_context *context = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    dict = getdns_context_get_api_information(context);

    /* Return the address of the dictionary. */
    RETURN_LONG((long) dict);
}

/**
 * Function to set the append name method.
 */
PHP_FUNCTION(php_getdns_context_set_append_name)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_append_name_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (getdns_append_name_t) phpValue;
    result = getdns_context_set_append_name(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the context update callback function.
 */
PHP_FUNCTION(php_getdns_context_set_update_callback)
{
    long phpContext = 0;
    zval *phpUserArg = NULL;
    getdns_context *context = NULL;
    getdns_return_t result;
    void *userArg = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz",
        &phpContext, &phpUserArg) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpUserArg) == IS_ARRAY) {
        userArg = (void *) phpUserArg;
    }
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;

    result = getdns_context_set_update_callback(context, userArg,
                                                context_update_callback);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set DNS root servers.
 */
PHP_FUNCTION(php_getdns_context_set_dns_root_servers)
{
    long phpContext = 0, phpList = 0;
    getdns_context *context = NULL;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    list = (getdns_list *) phpList;
    result = getdns_context_set_dns_root_servers(context, list);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the transport arrangements.
 */
PHP_FUNCTION(php_getdns_context_set_dns_transport)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_transport_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (getdns_transport_t) phpValue;
    result = getdns_context_set_dns_transport(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set a list of preferred transport protocols
 * in priority order.
 */
PHP_FUNCTION(php_getdns_context_set_dns_transport_list)
{
    long phpContext = 0, phpCount = 0;
    zval *phpArray, **arrayData = NULL;
    HashTable *arrayHash = NULL;
    HashPosition hashPtr = NULL;
    getdns_context *context = NULL;
    size_t count = 0;
    int arrayCount = 0;
    getdns_transport_list_t *transports = NULL, *valPtr = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpContext,
	 &phpCount, &phpArray) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters. */
    context = (getdns_context *) phpContext;
    count = (size_t) phpCount;

    /* The list of transports is received in an array. Convert the array. */
    if (Z_TYPE_P(phpArray) != IS_ARRAY) {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Convert the PHP array to an array of namespace values. */
    arrayHash = Z_ARRVAL_P(phpArray);
    arrayCount = zend_hash_num_elements(arrayHash);
    if (arrayCount != count) {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER); 
    }

    transports = malloc(count * sizeof(getdns_transport_list_t));
    if (transports) {
        valPtr = transports;
        for (zend_hash_internal_pointer_reset_ex(arrayHash, &hashPtr);
             zend_hash_get_current_data_ex(arrayHash, (void**) &arrayData, &hashPtr) == SUCCESS;
             zend_hash_move_forward_ex(arrayHash, &hashPtr)) {
            if (Z_TYPE_PP(arrayData) == IS_LONG) {
	        *valPtr = (getdns_transport_list_t) Z_LVAL_PP(arrayData);
	        *valPtr++;
	    }
	    else {
	        free(transports);
	        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
	    }
        }

        result = getdns_context_set_dns_transport_list(context, count, transports);
        free(transports);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
    }

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set DNSSEC allowed skew.
 */
PHP_FUNCTION(php_getdns_context_set_dnssec_allowed_skew)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    uint32_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (uint32_t) phpValue;
    result = getdns_context_set_dnssec_allowed_skew(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set DNSSEC trust anchors.
 */
PHP_FUNCTION(php_getdns_context_set_dnssec_trust_anchors)
{
    long phpContext = 0, phpList = 0;
    getdns_context *context = NULL;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    list = (getdns_list *) phpList;
    result = getdns_context_set_dnssec_trust_anchors(context, list);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the EDNS client subnet private option.
 */
PHP_FUNCTION(php_getdns_context_set_edns_client_subnet_private)
{
    long phpPtr = 0;
    zend_bool phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint8_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
        (ZEND_NUM_ARGS()TSRMLS_CC, "lb", &phpPtr, &phpValue) == FAILURE) {
        RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint8_t) phpValue;
    result = getdns_context_set_edns_client_subnet_private(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the EDNS DO bit.
 */
PHP_FUNCTION(php_getdns_context_set_edns_do_bit)
{
    long phpPtr = 0;
    zend_bool phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint8_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lb", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint8_t) phpValue;
    result = getdns_context_set_edns_do_bit(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set an EDNS extended RCODE.
 */
PHP_FUNCTION(php_getdns_context_set_edns_extended_rcode)
{
    long phpPtr = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint8_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint8_t) phpValue;
    result = getdns_context_set_edns_extended_rcode(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the EDNS maximum UDP payload size.
 */
PHP_FUNCTION(php_getdns_context_set_edns_maximum_udp_payload_size)
{
    long phpPtr = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint16_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint16_t) phpValue;
    result =
	getdns_context_set_edns_maximum_udp_payload_size(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the EDNS version.
 */
PHP_FUNCTION(php_getdns_context_set_edns_version)
{
    long phpPtr = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint8_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint8_t) phpValue;
    result = getdns_context_set_edns_version(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the redirect policy.
 */
PHP_FUNCTION(php_getdns_context_set_follow_redirects)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_redirects_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (getdns_redirects_t) phpValue;
    result = getdns_context_set_follow_redirects(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the idle timeout.
 */
PHP_FUNCTION(php_getdns_context_set_idle_timeout)
{
    long phpPtr = 0;
    zval *phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint64_t value = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate parameters. */
    if (Z_TYPE_P(phpValue) == IS_STRING) {
    	char *valStr = Z_STRVAL_P(phpValue);
	char *endPtr = NULL;

	value = (uint64_t) strtoull(valStr, &endPtr, 16);
    }   
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    result = getdns_context_set_idle_timeout(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the outstanding query limit.
 */
PHP_FUNCTION(php_getdns_context_set_limit_outstanding_queries)
{
    long phpPtr = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint16_t value;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    value = (uint16_t) phpValue;
    result = getdns_context_set_limit_outstanding_queries(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the namespace types.
 */
PHP_FUNCTION(php_getdns_context_set_namespaces)
{
    long phpContext = 0, phpCount = 0;
    zval *phpValue = NULL, **arrayData = NULL;
    HashTable *arrayHash = NULL;
    HashPosition hashPtr = NULL;
    int arrayCount = 0;
    getdns_context *context = NULL;
    size_t count = 0;
    getdns_namespace_t *value = NULL, *valPtr = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lla", &phpContext, &phpCount,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    count = (size_t) phpCount;

    /* Convert the PHP array to an array of namespace values. */
    arrayHash = Z_ARRVAL_P(phpValue);
    arrayCount = zend_hash_num_elements(arrayHash);
    if (arrayCount != count) {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER); 
    }

    value = malloc(count * sizeof(getdns_namespace_t));
    if (value) {
        valPtr = value;
        for (zend_hash_internal_pointer_reset_ex(arrayHash, &hashPtr);
             zend_hash_get_current_data_ex(arrayHash, (void**) &arrayData, &hashPtr) == SUCCESS;
             zend_hash_move_forward_ex(arrayHash, &hashPtr)) {
            if (Z_TYPE_PP(arrayData) == IS_LONG) {
	        *valPtr = (getdns_namespace_t) Z_LVAL_PP(arrayData);
	        *valPtr++;
	    }
	    else {
	        free(value);
	        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
	    }
        }

        result = getdns_context_set_namespaces(context, count, value);
        free(value);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
    }

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the resolution type.
 */
PHP_FUNCTION(php_getdns_context_set_resolution_type)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_resolution_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
  	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
 	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (getdns_resolution_t) phpValue;
    result = getdns_context_set_resolution_type(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the primary DNS suffix.
 */
PHP_FUNCTION(php_getdns_context_set_suffix)
{
    long phpContext = 0, phpList = 0;
    getdns_context *context = NULL;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    list = (getdns_list *) phpList;
    result = getdns_context_set_suffix(context, list);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the timeout.
 */
PHP_FUNCTION(php_getdns_context_set_timeout)
{
    long phpPtr = 0;
    zval *phpValue = 0;
    getdns_context *context = NULL;
    getdns_return_t result;
    uint64_t value = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpPtr, &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate parameters. */
    if (Z_TYPE_P(phpValue) == IS_STRING) {
    	char *valStr = Z_STRVAL_P(phpValue);
	char *endPtr = NULL;

	value = (uint64_t) strtoull(valStr, &endPtr, 16);
    }   
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    result = getdns_context_set_timeout(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the TLS authentication type.
 */
PHP_FUNCTION(php_getdns_context_set_tls_authentication)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    getdns_tls_authentication_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
  	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
 	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (getdns_tls_authentication_t) phpValue;
    result = getdns_context_set_tls_authentication(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the TLS query padding block size.
 */
PHP_FUNCTION(php_getdns_context_set_tls_query_padding_blocksize)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    uint16_t value = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
        (ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
         &phpValue) == FAILURE) {
        RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    value = (uint16_t) phpValue;
    result = getdns_context_set_tls_query_padding_blocksize(context, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set upstream recursive servers.
 */
PHP_FUNCTION(php_getdns_context_set_upstream_recursive_servers)
{
    long phpContext = 0, phpList = 0;
    getdns_context *context = NULL;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    list = (getdns_list *) phpList;
    result = getdns_context_set_upstream_recursive_servers(context, list);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to convert an IDN A-label to an IDN U-label.
 */
PHP_FUNCTION(php_getdns_convert_alabel_to_ulabel)
{
    char *phpStr = NULL, *uLabel = NULL;
    size_t phpStrLen = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "s", &phpStr, &phpStrLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    uLabel = getdns_convert_alabel_to_ulabel(phpStr);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    if (uLabel) {
        RETVAL_STRING(uLabel, 1);
        free(uLabel);
    }
    else {
        RETURN_NULL();
    }
}

/**
 * Function to convert a DNS name in wire format to a fully-qualified domain name in string format.
 */
PHP_FUNCTION(php_getdns_convert_dns_name_to_fqdn)
{
    char *phpPtr = NULL, *fqdn = NULL;
    zval *phpOut = NULL;
    int phpPtrLen = 0, fqdnLen = 0;
    getdns_bindata dnsName = {0, NULL};
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "sz",
            &phpPtr, &phpPtrLen, &phpOut) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dnsName.size = phpPtrLen;
    dnsName.data = phpPtr;
    result = getdns_convert_dns_name_to_fqdn(&dnsName, &fqdn);
    convert_to_null(phpOut);
    if (fqdn) {
        fqdnLen = strlen(fqdn);

        /* Store the output value and return the result. */
        convert_to_string(phpOut);
        Z_STRVAL_P(phpOut) = estrdup(fqdn);
        Z_STRLEN_P(phpOut) = fqdnLen;
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a FQDN in string format to a DNS name in wire format.
 */
PHP_FUNCTION(php_getdns_convert_fqdn_to_dns_name)
{
    char *phpStr = NULL;
    size_t phpStrLen = 0;
    zval *phpOut = NULL;
    getdns_bindata *dnsName = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "sz", &phpStr, &phpStrLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    result = getdns_convert_fqdn_to_dns_name(phpStr, &dnsName);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    if (dnsName->data) {
        ZVAL_STRINGL(phpOut, (char *) dnsName->data, dnsName->size, 1);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert an IDN U-label to an IDN A-label.
 */
PHP_FUNCTION(php_getdns_convert_ulabel_to_alabel)
{
    char *phpStr = NULL;
    size_t phpStrLen = 0;
    char *aLabel = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "s", &phpStr, &phpStrLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    aLabel = getdns_convert_ulabel_to_alabel(phpStr);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    if (aLabel) {
        RETVAL_STRING(aLabel, 1);
        free(aLabel);
    }
    else {
        RETURN_NULL();
    }
}

/**
 * Function to create a new dictionary with no associated context.
 */
PHP_FUNCTION(php_getdns_dict_create)
{
    getdns_dict *dict = NULL;

    /* There are no parameters - call the function.
       Note that the return value is NULL if there is unsufficient memory to create the dictionary. */
    dict = getdns_dict_create();

    /* Return the address of the dictionary. */
    RETURN_LONG((long) dict);
}

/**
 * Function to create a new dictionary with an associated context.
 */
PHP_FUNCTION(php_getdns_dict_create_with_context)
{
    long phpPtr = 0;
    getdns_dict *dict = NULL;
    getdns_context *context = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    dict = getdns_dict_create_with_context(context);

    /* Return the address of the dictionary. */
    RETURN_LONG((long) dict);
}

/**
 * Function to destroy a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_destroy)
{
    getdns_dict *dict = NULL;
    long phpDict;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpDict) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    getdns_dict_destroy(dict);

    /* There is no return value. */
    RETURN_NULL();
}

/**
 * Function to retrieve a bindata value from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_bindata)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    zval *phpBindata = NULL;
    getdns_bindata *answer;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpPtr,
	 &phpName, &phpNameLen, &phpBindata) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_bindata(dict, phpName, &answer);

    /* Store the output value and return the result. */
    convert_to_null(phpBindata);
    if (answer) {
        if (answer->data) {
            ZVAL_STRINGL(phpBindata, (char *) answer->data, answer->size, 1);
        }
    }
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a data type from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_data_type)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    zval *phpOut = NULL;
    getdns_data_type dataType = 0;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpPtr, &phpName,
	 &phpNameLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_data_type(dict, phpName, &dataType);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) dataType);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a dictionary from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_dict)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    zval *phpOut = NULL;
    getdns_dict *dict = NULL, *ansDict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpPtr, &phpName,
	 &phpNameLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_dict(dict, phpName, &ansDict);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) ansDict);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve an integer from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_int)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    zval *phpOut = NULL;
    uint32_t answer;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpPtr, &phpName,
	 &phpNameLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_int(dict, phpName, &answer);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) answer);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a list from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_list)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    zval *phpOut = NULL;
    getdns_list *list = NULL;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpPtr, &phpName,
	 &phpNameLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_list(dict, phpName, &list);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) list);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a list of names from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_get_names)
{
    long phpPtr = 0;
    zval *phpOut = NULL;
    getdns_list *list = NULL;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpPtr, &phpOut) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    result = getdns_dict_get_names(dict, &list);

    /* Store the output value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) list);
    RETURN_LONG((long) result);
}

/**
 * Function to remove a value associated with a name from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_remove_name)
{
    long phpPtr = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    getdns_dict *dict = NULL;
    char *name = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ls", &phpPtr, &phpName,
	 &phpNameLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    name = phpName;
    result = getdns_dict_remove_name(dict, name);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to assign child bindata to an item in a parent dictionary.
 */
PHP_FUNCTION(php_getdns_dict_set_bindata)
{
    long phpDict = 0;
    char *phpName = NULL, *phpBindata = NULL;
    size_t phpNameLen = 0, phpBindataLen = 0;
    getdns_return_t result = 0;
    getdns_dict *dict = NULL;
    getdns_bindata bindata = {0, NULL};
    char *name = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lss", &phpDict, &phpName, &phpNameLen,
	 &phpBindata, &phpBindataLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    name = phpName;
    bindata.size = phpBindataLen;
    bindata.data = (void *) phpBindata;
    result = getdns_dict_set_bindata(dict, name, &bindata);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to assign a child dictionary to an item in a parent dictionary.
 */
PHP_FUNCTION(php_getdns_dict_set_dict)
{
    long phpPDict = 0, phpCDict = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    getdns_return_t result = 0;
    getdns_dict *pDict = NULL, *cDict = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsl", &phpPDict, &phpName, &phpNameLen,
	 &phpCDict) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    pDict = (getdns_dict *) phpPDict;
    cDict = (getdns_dict *) phpCDict;
    result = getdns_dict_set_dict(pDict, phpName, cDict);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the integer value of an indexed item in a parent dictionary.
 */
PHP_FUNCTION(php_getdns_dict_set_int)
{
    long phpDict = 0, phpInt = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    getdns_return_t result = 0;
    getdns_dict *dict = NULL;
    uint32_t childInt = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsl", &phpDict, &phpName, &phpNameLen,
	 &phpInt) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    childInt = (uint32_t) phpInt;
    result = getdns_dict_set_int(dict, phpName, childInt);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to assign a child list to an item in a parent dictionary.
 */
PHP_FUNCTION(php_getdns_dict_set_list)
{
    long phpDict = 0, phpList = 0;
    char *phpName = NULL;
    size_t phpNameLen = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    getdns_dict *dict = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsl", &phpDict, &phpName, &phpNameLen,
	 &phpList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    list = (getdns_list *) phpList;
    result = getdns_dict_set_list(dict, phpName, list);

    /* Return the result. */
    RETURN_LONG((long) result);
}


/**
 * Function to retrieve and format an IP address.
 */
PHP_FUNCTION(php_getdns_display_ip_address)
{
    char *phpBindata = NULL;
    size_t phpBindataLen = 0;
    getdns_bindata bindata = {0, NULL};
    char *ipAddress = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "s",
        &phpBindata, &phpBindataLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    bindata.size = phpBindataLen;
    bindata.data = (void *) phpBindata;
    ipAddress = getdns_display_ip_address(&bindata);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    RETVAL_STRING(ipAddress, 1);
    free(ipAddress);
}

/**
 * Function to asynchronously retrieve general DNS data.
 */
PHP_FUNCTION(php_getdns_general)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpReqType = 0, phpExtensions = 0;
    char *name = NULL;
    size_t nameLen = 0;
    zval *phpTrans = NULL, *phpUserArg = NULL;
    uint16_t requestType = 0;
    getdns_dict *extensions = NULL;
    void *userArg = NULL;
    getdns_transaction_t trans = 0, *transPtr;
    char *endPtr = NULL, *transIDStr = NULL, *transStr = NULL;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsllzz", &phpContext, &name, &nameLen,
	 &phpReqType, &phpExtensions, &phpUserArg, &phpTrans) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpUserArg) == IS_ARRAY) {
        userArg = (void *) phpUserArg;
    }
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    switch (Z_TYPE_P(phpTrans)) {
        case IS_NULL:
    	    transPtr = NULL;
    	    break;
    	case IS_STRING:
	    transStr = Z_STRVAL_P(phpTrans);
    	    endPtr = NULL;

    	    trans = (uint64_t) strtoull(transStr, &endPtr, 16);
            transPtr = &trans;
	    break;
        default:
    	    RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    requestType = (uint16_t) phpReqType;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_general(context, name, requestType,
                            extensions, userArg,
			    transPtr, async_callback);

    /* Return the transaction identifier and the result. */
    if (transPtr) {
        convert_to_null(phpTrans);
        transIDStr = (char *) malloc(transIDSize + 1);
        if (transIDStr) {
            snprintf(transIDStr, transIDSize + 1, "%016llX", (unsigned long long) trans);
            ZVAL_STRING(phpTrans, transIDStr, 1);
            free(transIDStr);
        }
    }
    RETURN_LONG((long) result);
}

/**
 * Function to synchronously retrieve general DNS data.
 */
PHP_FUNCTION(php_getdns_general_sync)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpRequestType = 0, phpExtensions = 0;
    zval *phpOut = NULL;
    char *name = NULL;
    size_t nameLen = 0;
    uint16_t requestType = 0;
    getdns_dict *extensions = NULL, *response = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsllz", &phpContext, &name, &nameLen,
	 &phpRequestType, &phpExtensions, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    requestType = (uint16_t) phpRequestType;
    extensions = (getdns_dict *) phpExtensions;
    result =
	getdns_general_sync(context, name, requestType, extensions,
			    &response);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) response);
    RETURN_LONG((long) result);
}

/**
 * Function to asynchronously retrieve a host name assigned to an IP address.
 */
PHP_FUNCTION(php_getdns_hostname)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpDict = 0, phpExtensions = 0;
    getdns_dict *address = NULL, *extensions = NULL;
    zval *phpTrans = NULL, *phpUserArg = NULL;
    void *userArg = NULL;
    getdns_transaction_t trans = 0, *transPtr;
    char *endPtr = NULL, *transIDStr = NULL, *transStr = NULL;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lllzz", &phpContext, &phpDict,
	 &phpExtensions, &phpUserArg, &phpTrans) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpUserArg) == IS_ARRAY) {
        userArg = (void *) phpUserArg;
    }
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    switch (Z_TYPE_P(phpTrans)) {
        case IS_NULL:
    	    transPtr = NULL;
    	    break;
    	case IS_STRING:
	    transStr = Z_STRVAL_P(phpTrans);
    	    endPtr = NULL;

    	    trans = (uint64_t) strtoull(transStr, &endPtr, 16);
            transPtr = &trans;
	    break;
        default:
    	    RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    address = (getdns_dict *) phpDict;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_hostname(context, address, extensions,
                             userArg, transPtr,
			     async_callback);

    /* Return the transaction identifier and the result. */
    if (transPtr) {
        convert_to_null(phpTrans);
        transIDStr = (char *) malloc(transIDSize + 1);
        if (transIDStr) {
            snprintf(transIDStr, transIDSize + 1, "%016llX", (unsigned long long) trans);
            ZVAL_STRING(phpTrans, transIDStr, 1);
            free(transIDStr);
        }
    }
    RETURN_LONG((long) result);
}

/**
 * Function to synchronously retrieve a host name assigned to an IP address.
 */
PHP_FUNCTION(php_getdns_hostname_sync)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpAddress = 0, phpExtensions = 0;
    zval *phpOut = NULL;
    getdns_dict *address = NULL, *extensions = NULL, *response = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lllz", &phpContext, &phpAddress,
	 &phpExtensions, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    address = (getdns_dict *) phpAddress;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_hostname_sync(context, address, extensions, &response);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) response);
    RETURN_LONG((long) result);
}

/**
 * Function to create a new list with no associated context.
 */
PHP_FUNCTION(php_getdns_list_create)
{
    getdns_list *list = NULL;

    /* There are no parameters - call the function.
       Note that the return value is NULL if there is unsufficient memory to create the list. */
    list = getdns_list_create();

    /* Return the address of the list. */
    RETURN_LONG((long) list);
}

/**
 * Function to create a new list with an associated context.
 */
PHP_FUNCTION(php_getdns_list_create_with_context)
{
    long phpPtr = 0;
    getdns_list *list = NULL;
    getdns_context *context = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpPtr;
    list = getdns_list_create_with_context(context);

    /* Return the address of the list. */
    RETURN_LONG((long) list);
}

/**
 * Function to destroy a list.
 */
PHP_FUNCTION(php_getdns_list_destroy)
{
    long phpPtr = 0;
    getdns_list *list = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpPtr;
    getdns_list_destroy(list);

    /* There is no return value. */
    RETURN_NULL();
}

/**
 * Function to retrieve a bindata value from a list.
 */
PHP_FUNCTION(php_getdns_list_get_bindata)
{
    long phpPtr = 0, phpIndex = 0;
    zval *phpBindata = NULL;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    getdns_bindata *answer = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpPtr,
	&phpIndex, &phpBindata) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpPtr;
    index = (size_t) phpIndex;
    result = getdns_list_get_bindata(list, index, &answer);

    /* Store the response value and return the result. */
    convert_to_null(phpBindata);
    if (answer) {
        if (answer->data) {
            ZVAL_STRINGL(phpBindata, (char *) answer->data, answer->size, 1);
	}
    }
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a data type from a list.
 */
PHP_FUNCTION(php_getdns_list_get_data_type)
{
    long phpPtr = 0, phpIndex = 0;
    zval *phpOut = NULL;
    size_t index = 0;
    const getdns_list *list = NULL;
    getdns_data_type dataType = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpPtr, &phpIndex, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (const getdns_list *) phpPtr;
    index = (size_t) phpIndex;
    result = getdns_list_get_data_type(list, index, &dataType);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) dataType);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a dictionary from a list.
 */
PHP_FUNCTION(php_getdns_list_get_dict)
{
    long phpPtr = 0, phpIndex = 0;
    zval *phpOut = NULL;
    size_t index = 0;
    const getdns_list *list = NULL;
    getdns_dict *dict = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpPtr, &phpIndex, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (const getdns_list *) phpPtr;
    index = (size_t) phpIndex;
    result = getdns_list_get_dict(list, index, &dict);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) dict);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve an integer from a list.
 */
PHP_FUNCTION(php_getdns_list_get_int)
{
    long phpPtr = 0, phpIndex = 0;
    zval *phpOut = NULL;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    uint32_t answer = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpPtr, &phpIndex, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpPtr;
    index = (size_t) phpIndex;
    result = getdns_list_get_int(list, index, &answer);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) answer);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the length of a list.
 */
PHP_FUNCTION(php_getdns_list_get_length)
{
    long phpPtr = 0;
    zval *phpOut = NULL;
    size_t length;
    getdns_return_t result = 0;
    const getdns_list *list = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpPtr, &phpOut) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (const getdns_list *) phpPtr;
    result = getdns_list_get_length(list, &length);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) length);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve a list from a list.
 */
PHP_FUNCTION(php_getdns_list_get_list)
{
    long phpPtr = 0, phpIndex = 0;
    zval *phpOut = NULL;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL, *ansList = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "llz", &phpPtr, &phpIndex, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpPtr;
    index = (size_t) phpIndex;
    result = getdns_list_get_list(list, index, &ansList);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) ansList);
    RETURN_LONG((long) result);
}

/**
 * Function to assign child bindata to an item in a parent list.
 */
PHP_FUNCTION(php_getdns_list_set_bindata)
{
    long phpList = 0, phpIndex = 0;
    char *phpBindata = NULL;
    size_t phpBindataLen = 0;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    getdns_bindata bindata = {0, NULL};

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lls", &phpList, &phpIndex,
	 &phpBindata, &phpBindataLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpList;
    index = (size_t) phpIndex;
    bindata.size = phpBindataLen;
    bindata.data = (void *) phpBindata;
    result = getdns_list_set_bindata(list, index, &bindata);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to assign a child dictionary to an item in a parent list.
 */
PHP_FUNCTION(php_getdns_list_set_dict)
{
    long phpList = 0, phpIndex = 0, phpDict = 0;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    getdns_dict *dict = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lll", &phpList, &phpIndex,
	 &phpDict) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpList;
    index = (size_t) phpIndex;
    dict = (getdns_dict *) phpDict;
    result = getdns_list_set_dict(list, index, dict);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to set the integer value of an indexed item in a parent list.
 */
PHP_FUNCTION(php_getdns_list_set_int)
{
    long phpList = 0, phpIndex = 0, phpInt = 0;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *list = NULL;
    uint32_t childInt = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lll", &phpList, &phpIndex,
	 &phpInt) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpList;
    index = (size_t) phpIndex;
    childInt = (uint32_t) phpInt;
    result = getdns_list_set_int(list, index, childInt);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to assign a child list to an item in a parent list.
 */
PHP_FUNCTION(php_getdns_list_set_list)
{
    long phpPList = 0, phpIndex = 0, phpCList = 0;
    size_t index = 0;
    getdns_return_t result = 0;
    getdns_list *pList = NULL, *cList = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lll", &phpPList, &phpIndex,
	 &phpCList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    pList = (getdns_list *) phpPList;
    index = (size_t) phpIndex;
    cList = (getdns_list *) phpCList;
    result = getdns_list_set_list(pList, index, cList);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to create a pin from a string.
 */
PHP_FUNCTION(php_getdns_pubkey_pin_create_from_string)
{
    getdns_dict *dict = NULL;
    long phpContext = 0;
    char *phpStr = NULL;
    size_t phpStrLen = 0;
    getdns_context *context = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "ls", &phpContext,
	 &phpStr, &phpStrLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    if (phpContext != 0) {
        /* Keep context NULL. */
        context = (getdns_context *) phpContext;
    }
    if (phpStrLen == 0) {
        phpStr = NULL;
    }

    /* Call the function.
       Note that the return value is NULL if the string did not match the context. */
    dict = getdns_pubkey_pin_create_from_string(context, phpStr);

    /* Return the address of the dictionary. */
    RETURN_LONG((long) dict);
}

/**
 * Function to validate a pin set.
 */
PHP_FUNCTION(php_getdns_pubkey_pinset_sanity_check)
{
    long phpPinSet = 0, phpErrorList = 0;
    getdns_list *pinSet = NULL, *errorList = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "ll",
	 &phpPinSet, &phpErrorList) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    pinSet = (getdns_list *) phpPinSet;
    errorList = (getdns_list *) phpErrorList;
    result = getdns_pubkey_pinset_sanity_check(pinSet, errorList);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to get the root trust anchor.
 */
PHP_FUNCTION(php_getdns_root_trust_anchor)
{
    zval *phpDate;
    getdns_list *list = NULL;
    time_t anchorDate = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &phpDate) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = getdns_root_trust_anchor(&anchorDate);
    convert_to_null(phpDate);
    ZVAL_LONG(phpDate, (long) anchorDate);

    /* Return the address of the list. */
    if (list) {
        RETURN_LONG((long) list);
    }
    else {
        RETURN_LONG(0);
    }
}

/**
 * Function to convert a resource record dictionary to string format.
 */
PHP_FUNCTION(php_getdns_rr_dict2str)
{
    long phpDict = 0;
    zval *phpStr = NULL;
    getdns_dict *dict = NULL;
    char *str = NULL;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpDict, &phpStr) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    result = getdns_rr_dict2str(dict, &str);

    if (str) {
        /* Store the output value and return the result. */
        convert_to_string(phpStr);
        Z_STRVAL_P(phpStr) = estrdup(str);
        Z_STRLEN_P(phpStr) = strlen(str);
        free(str);
    }
    else {
        convert_to_null(phpStr);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record dictionary to string format.
 */
PHP_FUNCTION(php_getdns_rr_dict2str_buf)
{
    long phpDict = 0;
    zval *phpStr = NULL, *phpStrLen = NULL;
    getdns_dict *dict = NULL;
    char *str = NULL;
    size_t strLen = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lzz", &phpDict, &phpStr,
	 &phpStrLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    strLen = Z_LVAL_P(phpStrLen);
    if (Z_TYPE_P(phpStr) != IS_STRING || Z_STRLEN_P(phpStr) != strLen) {
        convert_to_null(phpStrLen); 
        ZVAL_LONG(phpStrLen, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    str = malloc(strLen);
    if (str) {
        result = getdns_rr_dict2str_buf(dict, str, &strLen);
        /* Store the output value and return the result. */
        Z_STRVAL_P(phpStr) = estrdup(str);
        Z_STRLEN_P(phpStr) = strLen;
        convert_to_null(phpStrLen);
        ZVAL_LONG(phpStrLen, (long) strLen);
        free(str);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
        convert_to_null(phpStrLen);
        ZVAL_LONG(phpStrLen, 0);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record dictionary to string format.
 */
PHP_FUNCTION(php_getdns_rr_dict2str_scan)
{
    long phpDict = 0;
    zval *phpStr = NULL, *phpStrLen = NULL;
    getdns_dict *dict = NULL;
    char *str = NULL;
    int strLen = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lzz", &phpDict, &phpStr,
	 &phpStrLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    strLen = Z_LVAL_P(phpStrLen);
    if (Z_TYPE_P(phpStr) != IS_STRING || Z_STRLEN_P(phpStr) != strLen) {
        convert_to_null(phpStrLen); 
        ZVAL_LONG(phpStrLen, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    str = malloc(strLen);
    if (str) {
        char *strTmp = str;

        result = getdns_rr_dict2str_scan(dict, &str, &strLen);
        /* Store the output value and return the result. */
        Z_STRVAL_P(phpStr) = estrdup(str);
        Z_STRLEN_P(phpStr) = strLen;
        convert_to_null(phpStrLen);
        ZVAL_LONG(phpStrLen, (long) strLen);
        free(strTmp);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
        convert_to_null(phpStrLen);
        ZVAL_LONG(phpStrLen, 0);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record dictionary to wire format.
 */
PHP_FUNCTION(php_getdns_rr_dict2wire)
{
    long phpDict = 0;
    zval *phpWire = NULL, *phpWireSize = NULL;
    getdns_dict *dict = NULL;
    uint8_t *wire = NULL;
    size_t wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lzz", &phpDict, &phpWire,
	 &phpWireSize) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    result = getdns_rr_dict2wire(dict, &wire, &wireSize);

    if (wire) {
        /* Store the output value and return the result. */
        convert_to_string(phpWire);
        Z_STRVAL_P(phpWire) = estrdup(wire);
        Z_STRLEN_P(phpWire) = wireSize;
        convert_to_null(phpWireSize);
        ZVAL_LONG(phpWireSize, (long) wireSize);
        free(wire);
    }
    else {
        convert_to_null(phpWire);
        ZVAL_LONG(phpWireSize, 0);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record dictionary to wire format.
 */
PHP_FUNCTION(php_getdns_rr_dict2wire_buf)
{
    long phpDict = 0;
    zval *phpWire = NULL, *phpWireSize = NULL;
    getdns_dict *dict = NULL;
    uint8_t *wire = NULL;
    size_t wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lzz", &phpDict, &phpWire,
	 &phpWireSize) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    wireSize = Z_LVAL_P(phpWireSize);
    if (Z_TYPE_P(phpWire) != IS_STRING || Z_STRLEN_P(phpWire) != wireSize) {
        convert_to_null(phpWireSize); 
        ZVAL_LONG(phpWireSize, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    wire = malloc(wireSize);
    if (wire) {
        result = getdns_rr_dict2wire_buf(dict, wire, &wireSize);
        /* Store the output value and return the result. */
        Z_STRVAL_P(phpWire) = estrdup(wire);
        Z_STRLEN_P(phpWire) = wireSize;
        convert_to_null(phpWireSize);
        ZVAL_LONG(phpWireSize, (long) wireSize);
        free(wire);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
        convert_to_null(phpWireSize);
        ZVAL_LONG(phpWireSize, 0);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record dictionary to wire format.
 */
PHP_FUNCTION(php_getdns_rr_dict2wire_scan)
{
    long phpDict = 0;
    zval *phpWire = NULL, *phpWireSize = NULL;
    getdns_dict *dict = NULL;
    uint8_t *wire = NULL;
    int wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lzz", &phpDict, &phpWire,
	 &phpWireSize) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    wireSize = Z_LVAL_P(phpWireSize);
    if (Z_TYPE_P(phpWire) != IS_STRING || Z_STRLEN_P(phpWire) != wireSize) {
        convert_to_null(phpWireSize); 
        ZVAL_LONG(phpWireSize, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    wire = malloc(wireSize);
    if (wire) {
        uint8_t *wireTmp = wire;

        result = getdns_rr_dict2wire_scan(dict, &wire, &wireSize);
        /* Store the output value and return the result. */
        Z_STRVAL_P(phpWire) = estrdup(wire);
        Z_STRLEN_P(phpWire) = wireSize;
        convert_to_null(phpWireSize);
        ZVAL_LONG(phpWireSize, (long) wireSize);
        free(wireTmp);
    }
    else {
        result = GETDNS_RETURN_MEMORY_ERROR;
        convert_to_null(phpWireSize);
        ZVAL_LONG(phpWireSize, 0);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to create a "pretty printed" representation of a dictionary.
 */
PHP_FUNCTION(php_getdns_pretty_print_dict)
{
    long phpPtr = 0;
    getdns_dict *dict = NULL;
    char *ppDict = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    if (!phpPtr) {
        RETURN_NULL();
    }
    dict = (getdns_dict *) phpPtr;
    ppDict = getdns_pretty_print_dict(dict);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    RETVAL_STRING(ppDict, 1);
    free(ppDict);
}

/**
 * Function to asynchronously retrieve a service assigned to a DNS name.
 */
PHP_FUNCTION(php_getdns_service)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpExtensions = 0;
    char *name = NULL;
    size_t nameLen = 0;
    zval *phpTrans = NULL, *phpUserArg = NULL;
    getdns_dict *extensions = NULL;
    void *userArg = NULL;
    getdns_transaction_t trans = 0, *transPtr;
    char *endPtr = NULL, *transIDStr = NULL, *transStr = NULL;
    size_t transIDSize = sizeof(getdns_transaction_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lslzz", &phpContext, &name, &nameLen,
	 &phpExtensions, &phpUserArg, &phpTrans) == FAILURE) {
	RETURN_NULL();
    }

    /* Validate arguments. */
    if (Z_TYPE_P(phpUserArg) == IS_ARRAY) {
        userArg = (void *) phpUserArg;
    }
    else {
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    switch (Z_TYPE_P(phpTrans)) {
        case IS_NULL:
    	    transPtr = NULL;
    	    break;
    	case IS_STRING:
	    transStr = Z_STRVAL_P(phpTrans);
    	    endPtr = NULL;

    	    trans = (uint64_t) strtoull(transStr, &endPtr, 16);
            transPtr = &trans;
	    break;
        default:
    	    RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_service(context, name, extensions,
                            userArg, transPtr,
			    async_callback);

    /* Return the transaction identifier and the result. */
    if (transPtr) {
        convert_to_null(phpTrans);
        transIDStr = (char *) malloc(transIDSize + 1);
        if (transIDStr) {
            snprintf(transIDStr, transIDSize + 1, "%016llX", (unsigned long long) trans);
            ZVAL_STRING(phpTrans, transIDStr, 1);
            free(transIDStr);
        }
    }
    RETURN_LONG((long) result);
}

/**
 * Function to synchronously retrieve a service assigned to a DNS name.
 */
PHP_FUNCTION(php_getdns_service_sync)
{
    getdns_return_t result = 0;
    struct getdns_context *context = NULL;
    long phpContext = 0, phpExtensions = 0;
    char *name = NULL;
    size_t nameLen = 0;
    zval *phpOut = NULL;
    getdns_dict *extensions = NULL, *response = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lslz", &phpContext, &name, &nameLen,
	 &phpExtensions, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Set up parameters and call the function. */
    context = (getdns_context *) phpContext;
    extensions = (getdns_dict *) phpExtensions;
    result = getdns_service_sync(context, name, extensions, &response);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) response);
    RETURN_LONG((long) result);
}

/**
 * Function to convert a resource record string to dictionary format.
 */
PHP_FUNCTION(php_getdns_str2rr_dict)
{
    long phpTTL = 0;
    zval *phpDict = NULL;
    char *phpRRStr = NULL, *phpOrigin = NULL;
    int phpRRStrLen = 0, phpOriginLen = 0;
    getdns_dict *dict = NULL;
    uint32_t defTTL = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "szsl",
        &phpRRStr, &phpRRStrLen, &phpDict,
        &phpOrigin, &phpOriginLen, &phpTTL) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    defTTL = phpTTL;
    result = getdns_str2rr_dict(phpRRStr, &dict, phpOrigin, defTTL);

    /* Store the response value and return the result. */
    convert_to_null(phpDict);
    ZVAL_LONG(phpDict, (long) dict);
    RETURN_LONG((long) result);
}

/**
 * Function to validate DNSSEC.
 */
PHP_FUNCTION(php_getdns_validate_dnssec)
{
    long phpPtr1 = 0, phpPtr2 = 0, phpPtr3 = 0;
    getdns_list *toValidate = NULL, *supportRecords = NULL, *trustAnchors =
	NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lll", &phpPtr1, &phpPtr2,
	 &phpPtr3) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    toValidate = (getdns_list *) phpPtr1;
    supportRecords = (getdns_list *) phpPtr2;
    trustAnchors = (getdns_list *) phpPtr3;
    result =
	getdns_validate_dnssec(toValidate, supportRecords, trustAnchors);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/* Functions from getdns_extra.h */

/**
 * Function to detach the event loop from a context.
 */
PHP_FUNCTION(php_getdns_context_detach_eventloop)
{
    long phpContext = 0;
    getdns_context *context = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpContext)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_detach_eventloop(context);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the append name value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_append_name)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_append_name_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_append_name(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the list of root servers from a context.
 */
PHP_FUNCTION(php_getdns_context_get_dns_root_servers)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_list *value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_dns_root_servers(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the DNS transport type value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_dns_transport)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_transport_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_dns_transport(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the DNSSEC allowed skew value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_dnssec_allowed_skew)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint32_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_dnssec_allowed_skew(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the list of DNSSEC trust anchors from a context.
 */
PHP_FUNCTION(php_getdns_context_get_dnssec_trust_anchors)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_list *value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_dnssec_trust_anchors(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the EDNS client subnet private value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_edns_client_subnet_private)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint8_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
        == FAILURE) {
        RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_edns_client_subnet_private(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_BOOL(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the EDNS DO bit value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_edns_do_bit)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint8_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_edns_do_bit(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_BOOL(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the EDNS extended RCODE value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_edns_extended_rcode)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint8_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_edns_extended_rcode(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the EDNS maximum UDP payload size value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_edns_maximum_udp_payload_size)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint16_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result =
	getdns_context_get_edns_maximum_udp_payload_size(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the EDNS version value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_edns_version)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint8_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_edns_version(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the follow redirects value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_follow_redirects)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_redirects_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_follow_redirects(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the outstanding query limit value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_limit_outstanding_queries)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint16_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_limit_outstanding_queries(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the list of upstream recursive servers from a context.
 */
PHP_FUNCTION(php_getdns_context_get_namespaces)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_namespace_t *value;
    size_t valCount;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_namespaces(context, &valCount, &value);

    /* Store the response value and return the result. */
    convert_to_array(phpOut);
    array_init(phpOut);
    if (result == GETDNS_RETURN_GOOD) {
	if (valCount > 0) {
	    size_t i;
	    getdns_namespace_t *valPtr = value;

	    for (i = 1; i <= valCount; i++) {
		add_next_index_long(phpOut, (long) *valPtr);
		valPtr++;
	    }
	    free(value);
	}
    }
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the number of pending requests from a context.
 */
PHP_FUNCTION(php_getdns_context_get_num_pending_requests)
{
    long phpContext = 0;
    getdns_context *context = NULL;
    uint32_t numRequests;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpContext)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function.
       NOTE: getdns_context_get_num_pending_requests() currently includes two arguments.
       The second is a time value for the next timeout. There's a note in the getdns source
       code about removing this argument. Set it to NULL. */
    context = (getdns_context *) phpContext;
    numRequests = getdns_context_get_num_pending_requests(context, NULL);

    /* Return the number of outstanding requests. */
    RETURN_LONG((long) numRequests);
}

/**
 * Function to retrieve the resolution type from a context.
 */
PHP_FUNCTION(php_getdns_context_get_resolution_type)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_resolution_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_resolution_type(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the list of suffix values from a context.
 */
PHP_FUNCTION(php_getdns_context_get_suffix)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_list *value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_suffix(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the timeout value from a context.
 */
PHP_FUNCTION(php_getdns_context_get_timeout)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint64_t value;
    getdns_return_t result;
    char *timeoutStr = NULL;
    size_t timeoutSize = sizeof(uint64_t) * 2;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_timeout(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    timeoutStr = (char *) malloc(timeoutSize + 1);
    if (timeoutStr) {
        timeoutStr[timeoutSize] = 0;
        snprintf(timeoutStr, timeoutSize + 1, "%016llX", (unsigned long long) value);
        ZVAL_STRINGL(phpOut, timeoutStr, timeoutSize, 1);
        free(timeoutStr);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the TLS authentication type from a context.
 */
PHP_FUNCTION(php_getdns_context_get_tls_authentication)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_tls_authentication_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
        == FAILURE) {
        RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_tls_authentication(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the TLS query pattern block size from a context.
 */
PHP_FUNCTION(php_getdns_context_get_tls_query_padding_blocksize)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    uint16_t value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
        == FAILURE) {
        RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_tls_query_padding_blocksize(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the current update callback parameters.
 */
PHP_FUNCTION(php_getdns_context_get_update_callback)
{
    typedef void (*getdns_update_callback2) (struct getdns_context *,
        getdns_context_code_t, void *userarg);
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    void *value = NULL;
    getdns_update_callback2 callback;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_get_update_callback(context, &value, &callback);

    /*
     * Store the response value and return the result.
     * Ignore the value of callback - it's the internal callback used here.
     * The client callback is the first element of the array (the value variable)
     * being passed back to the caller.
     */
    convert_to_null(phpOut);
    if (value) {
	zval *userArg = (zval *) value;

        array_init(phpOut);
	ZVAL_COPY_VALUE(phpOut, userArg);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to retrieve the list of upstream recursive servers from a context.
 */
PHP_FUNCTION(php_getdns_context_get_upstream_recursive_servers)
{
    long phpContext = 0;
    zval *phpOut = NULL;
    getdns_context *context = NULL;
    getdns_list *value;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpContext, &phpOut)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result =
	getdns_context_get_upstream_recursive_servers(context, &value);

    /* Store the response value and return the result. */
    convert_to_null(phpOut);
    ZVAL_LONG(phpOut, (long) value);
    RETURN_LONG((long) result);
}

/**
 * Function to process asynchronous requests.
 */
PHP_FUNCTION(php_getdns_context_process_async)
{
    long phpContext = 0;
    getdns_context *context = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpContext)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    result = getdns_context_process_async(context);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to run the context's event loop until there's nothing more to do.
 */
PHP_FUNCTION(php_getdns_context_run)
{
    long phpContext = 0;
    getdns_context *context = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpContext)
	== FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    getdns_context_run(context);

    /* There is no return value. */
    RETURN_NULL();
}

/**
 * Function to enable the return_dnssec_status extension on every request.
 */
PHP_FUNCTION(php_getdns_context_set_return_dnssec_status)
{
    long phpContext = 0, phpValue = 0;
    getdns_context *context = NULL;
    int enabled = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "ll", &phpContext,
	 &phpValue) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function.
       The phpValue should be either GETDNS_EXTENSION_TRUE or GETDNS_EXTENSION_FALSE. */
    context = (getdns_context *) phpContext;
    enabled = (int) phpValue;
    result = getdns_context_set_return_dnssec_status(context, enabled);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to tell the underlying unbound library to use background threads.
 */
PHP_FUNCTION(php_getdns_context_set_use_threads)
{
    long phpContext = 0;
    zend_bool phpUseThreads = 0;
    getdns_context *context = NULL;
    int useThreads = 0;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lb", &phpContext,
	 &phpUseThreads) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    context = (getdns_context *) phpContext;
    useThreads = (int) phpUseThreads;
    result = getdns_context_set_use_threads(context, useThreads);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to get a string from a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_util_get_string)
{
    long phpDict = 0;
    zval *phpOut = NULL;
    size_t nameLen = 0;
    int vLen = 0;
    getdns_dict *dict = NULL;
    char *name = NULL, *value = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lsz", &phpDict, &name,
	 &nameLen, &phpOut) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    result = getdns_dict_util_get_string(dict, name, &value);

    if (value) {
        vLen = strlen(value);

        /* Store the output value and return the result. */
        convert_to_string(phpOut);
        Z_STRVAL_P(phpOut) = estrdup(value);
        Z_STRLEN_P(phpOut) = vLen;
    }
    else {
        convert_to_null(phpOut);
    }
    RETURN_LONG((long) result);
}

/**
 * Function to set a string in a dictionary.
 */
PHP_FUNCTION(php_getdns_dict_util_set_string)
{
    long phpDict = 0;
    size_t nameLen = 0, valueLen = 0;
    getdns_dict *dict = NULL;
    char *name = NULL, *value = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "lss", &phpDict, &name, &nameLen,
	 &value, &valueLen) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpDict;
    result = getdns_dict_util_set_string(dict, name, value);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to convert a zone file to a list of dictionaries representing the RRs.
 */
PHP_FUNCTION(php_getdns_fp2rr_list)
{
    long phpTTL = 0;
    zval *phpList = NULL;
    char *phpFileName = NULL, *phpOrigin = NULL;
    int phpFileNameLen = 0, phpOriginLen = 0;
    FILE *fp = NULL;
    getdns_list *list = NULL;
    uint32_t defTTL = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "szsl",
        &phpFileName, &phpFileNameLen, &phpList,
        &phpOrigin, &phpOriginLen, &phpTTL) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    fp = fopen(phpFileName, "r");
    if (!fp) {
        convert_to_null(phpList);
        ZVAL_LONG(phpList, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    defTTL = phpTTL;
    result = getdns_fp2rr_list(fp, &list, phpOrigin, defTTL);
    fclose(fp);

    /* Store the response value and return the result. */
    convert_to_null(phpList);
    ZVAL_LONG(phpList, (long) list);
    RETURN_LONG((long) result);
}

/**
 * Function to translate an error code to a string.
 */
PHP_FUNCTION(php_getdns_get_errorstr_by_id)
{
    long phpPtr = 0;
    uint16_t err;
    const char *errorStr = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    err = (uint16_t) phpPtr;
    errorStr = getdns_get_errorstr_by_id(err);

    /* Return the result. */
    RETURN_STRING(errorStr, 1);
}

/**
 * Function to get the runtime API version number in string format.
 */
PHP_FUNCTION(php_getdns_get_api_version)
{
    const char *apiVersStr = NULL;

    /* Call the function. */
    apiVersStr = getdns_get_api_version();

    /* Return the result. */
    RETURN_STRING(apiVersStr, 1);
}

/**
 * Function to get the runtime API version number in number format.
 */
PHP_FUNCTION(php_getdns_get_api_version_number)
{
    uint32_t apiVersNum = 0;

    /* Call the function. */
    apiVersNum = getdns_get_api_version_number();

    /* Return the result. */
    RETURN_LONG(apiVersNum);
}

/**
 * Function to get the runtime library version number in string format.
 */
PHP_FUNCTION(php_getdns_get_version)
{
    const char *versStr = NULL;

    /* Call the function. */
    versStr = getdns_get_version();

    /* Return the result. */
    RETURN_STRING(versStr, 1);
}

/**
 * Function to get the runtime library version number in number format.
 */
PHP_FUNCTION(php_getdns_get_version_number)
{
    uint32_t versNum = 0;

    /* Call the function. */
    versNum = getdns_get_version_number();

    /* Return the result. */
    RETURN_LONG(versNum);
}

/**
 * Function to create a "pretty printed" representation of a list.
 */
PHP_FUNCTION(php_getdns_pretty_print_list)
{
    long phpPtr = 0;
    getdns_list *list = NULL;
    char *ppList = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "l", &phpPtr) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    if (!phpPtr) {
        RETURN_NULL();
    }
    list = (getdns_list *) phpPtr;
    ppList = getdns_pretty_print_list(list);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    if (ppList) {
        RETVAL_STRING(ppList, 1);
        free(ppList);
    }
    else {
	RETURN_NULL();
    }
}

/**
 * Function to create a JSON-formatted representation of a dictionary.
 */
PHP_FUNCTION(php_getdns_print_json_dict)
{
    long phpPtr = 0;
    zend_bool phpPretty = 0;
    getdns_dict *dict = NULL;
    int pretty = 0;
    char *ppDict = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lb", &phpPtr, &phpPretty) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    dict = (getdns_dict *) phpPtr;
    pretty = (int) phpPretty;
    ppDict = getdns_print_json_dict(dict, pretty);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    RETVAL_STRING(ppDict, 1);
    free(ppDict);
}

/**
 * Function to create a JSON-formatted representation of a list.
 */
PHP_FUNCTION(php_getdns_print_json_list)
{
    long phpPtr = 0;
    zend_bool phpPretty = 0;
    getdns_list *list = NULL;
    int pretty = 0;
    char *ppList = NULL;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lb", &phpPtr, &phpPretty) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    list = (getdns_list *) phpPtr;
    pretty = (int) phpPretty;
    ppList = getdns_print_json_list(list, pretty);

    /* Return the string value. Duplicate the string for PHP and free the local copy. */
    RETVAL_STRING(ppList, 1);
    free(ppList);
}

/**
 * Function to convert a wire format string to a resource record dictionary.
 */
PHP_FUNCTION(php_getdns_wire2rr_dict)
{
    char *phpWire = NULL;
    int phpWireLen = 0;
    long phpWireSize = 0;
    zval *phpDict = NULL;
    getdns_dict *dict = NULL;
    uint8_t *wire = NULL;
    size_t wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "slz",
         &phpWire, &phpWireLen, &phpWireSize, &phpDict) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    if (phpWireLen != phpWireSize) {
        convert_to_null(phpDict);
        ZVAL_LONG(phpDict, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    wire = (uint8_t *) phpWire;
    wireSize = phpWireSize;
    result = getdns_wire2rr_dict(wire, wireSize, &dict);

    /* Store the output value and return the result. */
    convert_to_null(phpDict);
    ZVAL_LONG(phpDict, (long) dict);
    RETURN_LONG((long) result);
}

/**
 * Function to convert a wire format string to a resource record dictionary.
 */
PHP_FUNCTION(php_getdns_wire2rr_dict_buf)
{
    char *phpWire = NULL;
    int phpWireLen = 0;
    zval *phpWireSize = NULL, *phpDict = NULL;
    getdns_dict *dict = NULL;
    uint8_t *wire = NULL;
    size_t wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "szz",
         &phpWire, &phpWireLen, &phpWireSize, &phpDict) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    wireSize = (size_t) Z_LVAL_P(phpWireSize);
    if (phpWireLen != wireSize) {
        convert_to_null(phpDict);
        ZVAL_LONG(phpDict, 0);
        RETURN_LONG((long) GETDNS_RETURN_INVALID_PARAMETER);
    }
    wire = (uint8_t *) phpWire;
    result = getdns_wire2rr_dict_buf(wire, &wireSize, &dict);

    /* Store the output values and return the result. */
    convert_to_null(phpDict);
    ZVAL_LONG(phpWireSize, (long) wireSize);
    ZVAL_LONG(phpDict, (long) dict);
    RETURN_LONG((long) result);
}

/**
 * Function to convert a wire format string to a resource record dictionary.
 */
PHP_FUNCTION(php_getdns_wire2rr_dict_scan)
{
    zval *phpWire = NULL, *phpWireSize = NULL, *phpDict = NULL;
    getdns_dict *dict = NULL;
    const uint8_t *wire = NULL;
    size_t wireSize = 0;
    getdns_return_t result = 0;

    /* Retrieve parameters. */
    if (zend_parse_parameters
	(ZEND_NUM_ARGS()TSRMLS_CC, "zzz",
         &phpWire, &phpWireSize, &phpDict) == FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters and call the function. */
    wire = (const uint8_t *) Z_STRVAL_P(phpWire);
    wireSize = (size_t) Z_LVAL_P(phpWireSize);
    result = getdns_wire2rr_dict_scan(&wire, &wireSize, &dict);

    /* Store the output values and return the result. */
    convert_to_null(phpDict);
    if (!result) {
        ZVAL_LONG(phpDict, (long) dict);
        ZVAL_LONG(phpWireSize, (long) wireSize);
        Z_STRVAL_P(phpWire) = estrdup(wire);
        Z_STRLEN_P(phpWire) = wireSize;
    }
    RETURN_LONG((long) result);
}

/* Internal utility functions for data structure conversion. */

getdns_return_t convert_array_internal_list(HashTable *hash, long *listAddr);
getdns_return_t convert_list_internal();

/**
 * Internal function to convert a PHP array to a getdns dictionary.
 */
getdns_return_t
convert_array_internal_dict(HashTable *hash, long *dictAddr)
{
    int type, type2;
    char *key, *key2;
    uint keyLen, keyLen2;
    ulong idx, idx2;
    uint32_t tmpInt;
    zval **ppData = NULL;
    HashTable *tmpArrayHash = NULL;
    getdns_bindata tmpBindata;
    getdns_dict *dict = NULL;
    getdns_return_t result;

    /* Create the dictionary. */
    dict = getdns_dict_create();
    if (!dict) {
        *dictAddr = 0;
        return(GETDNS_RETURN_MEMORY_ERROR);
    }
    *dictAddr = (long) dict;

    /* Examine each element in the array. */
    for (zend_hash_internal_pointer_reset(hash);
         zend_hash_has_more_elements(hash) == SUCCESS;
         zend_hash_move_forward(hash)) {

	/* Get the string value of the current key. */
	type = zend_hash_get_current_key_ex(hash, &key, &keyLen, &idx, 0, NULL);

	/* Get the data. */
	if (zend_hash_get_current_data(hash, (void **) &ppData) == FAILURE) {
	    /* This should never fail because the key is known to exist, but... */
	    result = GETDNS_RETURN_INVALID_PARAMETER;
	    break;
	}

	/* Process the different data types. */
	switch (Z_TYPE_PP(ppData)) {
	    case IS_LONG:
	        /* Type should be t_int. */
		tmpInt = (uint32_t) Z_LVAL_PP(ppData);
		result = getdns_dict_set_int(dict, key, tmpInt);
	        break;
            case IS_STRING:
	        /* Type should be t_bindata. */
		tmpBindata.data = Z_STRVAL_PP(ppData);
		tmpBindata.size = Z_STRLEN_PP(ppData);
		result = getdns_dict_set_bindata(dict, key, &tmpBindata);
		break;
	    case IS_ARRAY:
	        /* Type should be t_dict or t_list. */
                tmpArrayHash = Z_ARRVAL_PP(ppData);
	        type2 = zend_hash_get_current_key_ex(tmpArrayHash, &key2, &keyLen2, &idx2, 0, NULL);

		if (type2 == HASH_KEY_IS_STRING) {
		    /* Found an associative array. Convert to dictionary. */
		    long tmpDictAddr = 0;
		    getdns_dict *tmpDict = NULL;

		    result = convert_array_internal_dict(tmpArrayHash, &tmpDictAddr);
		    tmpDict = (getdns_dict *) tmpDictAddr;
		    if (result == GETDNS_RETURN_GOOD) {
		        result = getdns_dict_set_dict(dict, key, tmpDict);
		    }
		    getdns_dict_destroy(tmpDict);
		}
		else {
		    /* Found an indexed array. Convert to list. */
		    long tmpListAddr = 0;
		    getdns_list *tmpList = NULL;

		    result = convert_array_internal_list(tmpArrayHash, &tmpListAddr);
		    tmpList = (getdns_list *) tmpListAddr;
		    if (result == GETDNS_RETURN_GOOD) {
		        result = getdns_dict_set_list(dict, key, tmpList);
		    }
		    getdns_list_destroy(tmpList);
		}
		break;
	    default:
	        result = GETDNS_RETURN_INVALID_PARAMETER;
	}
	if (result != GETDNS_RETURN_GOOD) {
	    getdns_dict_destroy(dict);
	    *dictAddr = 0;
	    return(result);
	}
    }

    /* Return the result. */
    return(result);
}

/**
 * Internal function to convert a PHP array to a getdns list.
 */
getdns_return_t
convert_array_internal_list(HashTable *hash, long *listAddr)
{
    int type, type2;
    char *key, *key2;
    uint keyLen, keyLen2;
    ulong idx, idx2;
    uint32_t tmpInt;
    zval **ppData = NULL;
    HashTable *tmpArrayHash = NULL;
    getdns_bindata tmpBindata;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Create the list. */
    list = getdns_list_create();
    if (!list) {
        *listAddr = 0;
        return(GETDNS_RETURN_MEMORY_ERROR);
    }
    *listAddr = (long) list;

    /* Examine each element in the array. */
    for (zend_hash_internal_pointer_reset(hash);
         zend_hash_has_more_elements(hash) == SUCCESS;
         zend_hash_move_forward(hash)) {

	/* Get the string value of the current key. */
	type = zend_hash_get_current_key_ex(hash, &key, &keyLen, &idx, 0, NULL);

	/* Get the data. */
	if (zend_hash_get_current_data(hash, (void **) &ppData) == FAILURE) {
	    /* This should never fail because the key is known to exist, but... */
	    result = GETDNS_RETURN_INVALID_PARAMETER;
	    break;
	}

	/* Process the different data types. */
	switch (Z_TYPE_PP(ppData)) {
	    case IS_LONG:
	        /* Type should be t_int. */
		tmpInt = (uint32_t) Z_LVAL_PP(ppData);
		result = getdns_list_set_int(list, idx, tmpInt);
	        break;
            case IS_STRING:
	        /* Type should be t_bindata. */
		tmpBindata.data = Z_STRVAL_PP(ppData);
		tmpBindata.size = Z_STRLEN_PP(ppData);
		result = getdns_list_set_bindata(list, idx, &tmpBindata);
		break;
	    case IS_ARRAY:
	        /* Type should be t_dict or t_list. */
                tmpArrayHash = Z_ARRVAL_PP(ppData);
	        type2 = zend_hash_get_current_key_ex(tmpArrayHash, &key2, &keyLen2, &idx2, 0, NULL);

		if (type2 == HASH_KEY_IS_STRING) {
		    /* Found an associative array. Convert to dictionary. */
		    long tmpDictAddr = 0;
		    getdns_dict *tmpDict = NULL;

		    result = convert_array_internal_dict(tmpArrayHash, &tmpDictAddr);
		    tmpDict = (getdns_dict *) tmpDictAddr;
		    if (result == GETDNS_RETURN_GOOD) {
		        result = getdns_list_set_dict(list, idx, tmpDict);
		    }
		    getdns_dict_destroy(tmpDict);
		}
		else {
		    /* Found an indexed array. Convert to list. */
		    long tmpListAddr = 0;
		    getdns_list *tmpList = NULL;

		    result = convert_array_internal_list(tmpArrayHash, &tmpListAddr);
		    tmpList = (getdns_list *) tmpListAddr;
		    if (result == GETDNS_RETURN_GOOD) {
		        result = getdns_list_set_list(list, idx, tmpList);
		    }
		    getdns_list_destroy(tmpList);
		}
		break;
	    default:
	        result = GETDNS_RETURN_INVALID_PARAMETER;
	}
	if (result != GETDNS_RETURN_GOOD) {
	    getdns_list_destroy(list);
	    *listAddr = 0;
	    return(result);
	}
    }

    /* Return the result. */
    return(result);
}

/**
 * Internal function to convert a PHP array to a getdns dictionary or list.
 */
getdns_return_t
convert_array_internal(zval *phpArray, long *dictOrList)
{
    getdns_return_t result;
    HashTable *arrayHash = NULL;
    int type;
    char *key;
    uint keyLen;
    ulong idx;

    /* Initialize the value to be returned. */
    *dictOrList = 0;

    /*
     * Determine if this is an indexed or associative array.
     * Indexed arrays are converted to lists. Associative arrays
     * are converted to dictionaries. The caller must call the
     * appropriate destroy function when finished with the
     * returned value.
     */
    if (Z_TYPE_P(phpArray) != IS_ARRAY) {
        return(GETDNS_RETURN_INVALID_PARAMETER);
    }
    arrayHash = Z_ARRVAL_P(phpArray);
    type = zend_hash_get_current_key_ex(arrayHash, &key, &keyLen, &idx, 0, NULL);
    if (type == HASH_KEY_IS_STRING) {
        /* Have an associative array. Create a dictionary. */
        result = convert_array_internal_dict(arrayHash, dictOrList);
    }
    else {
        /* Have an indexed array. Create a list. */
        result = convert_array_internal_list(arrayHash, dictOrList);
    }

    /* return the result. */
    return(result);
}

/**
 * Internal function to convert a getdns dictionary to a PHP array.
 */
getdns_return_t
convert_dict_internal(const struct getdns_dict *dict, zval *retValue)
{
    getdns_bindata *tmpBindata = NULL;
    getdns_data_type dataType;
    getdns_dict *tmpDict = NULL;
    getdns_list *list = NULL, *tmpList = NULL;
    getdns_return_t result;
    size_t listLength;
    char *tmpName = NULL;
    size_t i;
    uint32_t tmpInt;
    zval *tmpArray = NULL;

    /* Initialize the array to be returned. */
    convert_to_null(retValue);
    array_init(retValue);

    /* Get the names from the dictionary. */
    result = getdns_dict_get_names(dict, &list);
    if (result != GETDNS_RETURN_GOOD) {
        if (list) {
	    getdns_list_destroy(list);
	}
	convert_to_null(retValue);
        return (result);
    }

    /* Walk through the list of names. */
    result = getdns_list_get_length(list, &listLength);
    if (result != GETDNS_RETURN_GOOD) {
	getdns_list_destroy(list);
	convert_to_null(retValue);
        return (result);
    }

    for (i = 0; i < listLength; i++) {
        result = getdns_list_get_data_type(list, i, &dataType);
	if (result != GETDNS_RETURN_GOOD) {
	    break;
	}

	/* The list should only contain the dictionary element names. */
	if (dataType = t_bindata) {
	    result = getdns_list_get_bindata(list, i, &tmpBindata);
	    if (result != GETDNS_RETURN_GOOD) {
		break;
	    }
    
            /* Each value should be a NULL-terminated string. */
	    tmpName = (char *) tmpBindata->data;

	    /* Use the name to get the type and value from the dictionary. */
	    result = getdns_dict_get_data_type(dict, tmpName, &dataType);
	    if (result != GETDNS_RETURN_GOOD) {
	        break;
	    }

	    switch (dataType) {
	        case t_int:
		    result = getdns_dict_get_int(dict, tmpName, &tmpInt);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
		    }
		    add_assoc_long(retValue, tmpName, tmpInt);
		    break;
                case t_bindata:
		    result = getdns_dict_get_bindata(dict, tmpName, &tmpBindata);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
		    }
		    add_assoc_stringl(retValue, tmpName, tmpBindata->data, tmpBindata->size, 1);
		    break;
		case t_dict:
		    result = getdns_dict_get_dict(dict, tmpName, &tmpDict);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
		    }
		    MAKE_STD_ZVAL(tmpArray);
		    array_init(tmpArray);
		    result = convert_dict_internal(tmpDict, tmpArray);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
                    }
                    add_assoc_zval(retValue, tmpName, tmpArray);
		    break;
		case t_list:
		    result = getdns_dict_get_list(dict, tmpName, &tmpList);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
		    }
		    MAKE_STD_ZVAL(tmpArray);
		    array_init(tmpArray);
		    result = convert_list_internal(tmpList, tmpArray);
		    if (result != GETDNS_RETURN_GOOD) {
		        break;
                    }
                    add_assoc_zval(retValue, tmpName, tmpArray);
		    break;
		default:
		    result = GETDNS_RETURN_GENERIC_ERROR;
	    }
	    if (result != GETDNS_RETURN_GOOD) {
                break;
            }
	}
	else {
	    result = GETDNS_RETURN_GENERIC_ERROR;
	    break;
	}
    }

    /* Return the result. */
    getdns_list_destroy(list);
    if (result != GETDNS_RETURN_GOOD) {
        convert_to_null(retValue);
    }
    return (result);
}

/**
 * Internal function to convert a getdns list to a PHP array.
 */
getdns_return_t
convert_list_internal(const struct getdns_list *list, zval *retValue)
{
    getdns_bindata *tmpBindata = NULL;
    getdns_data_type dataType;
    getdns_dict *tmpDict = NULL;
    getdns_list *tmpList = NULL;
    getdns_return_t result;
    size_t listLength;
    size_t i;
    uint32_t tmpInt;
    zval *tmpArray = NULL;

    /* Initialize the array to be returned. */
    convert_to_null(retValue);
    array_init(retValue);

    /* Walk through the list of names. */
    result = getdns_list_get_length(list, &listLength);
    if (result != GETDNS_RETURN_GOOD) {
	convert_to_null(retValue);
        return (result);
    }

    for (i = 0; i < listLength; i++) {
        result = getdns_list_get_data_type(list, i, &dataType);
	if (result != GETDNS_RETURN_GOOD) {
	    break;
	}

	/* The list can contain different types of data. */
	switch (dataType) {
	    case t_int:
                result = getdns_list_get_int(list, i, &tmpInt);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
		}
		add_index_long(retValue, i, tmpInt);
		break;
            case t_bindata:
	        result = getdns_list_get_bindata(list, i, &tmpBindata);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
		}
		add_index_stringl(retValue, i, tmpBindata->data, tmpBindata->size, 1);
		break;
            case t_dict:
                result = getdns_list_get_dict(list, i, &tmpDict);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
		}
		MAKE_STD_ZVAL(tmpArray);
		array_init(tmpArray);
		result = convert_dict_internal(tmpDict, tmpArray);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
                }
                add_index_zval(retValue, i, tmpArray);
		break;
            case t_list:
		result = getdns_list_get_list(list, i, &tmpList);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
		}
		MAKE_STD_ZVAL(tmpArray);
		array_init(tmpArray);
		result = convert_list_internal(tmpList, tmpArray);
		if (result != GETDNS_RETURN_GOOD) {
		    break;
                }
                add_index_zval(retValue, i, tmpArray);
		break;
            default:
                result = GETDNS_RETURN_GENERIC_ERROR;
        }
	if (result != GETDNS_RETURN_GOOD) {
            break;
        }
    }

    /* Return the result. */
    if (result != GETDNS_RETURN_GOOD) {
        convert_to_null(retValue);
    }
    return (result);
}

/* Non-API utility functions. */

/**
 * Function to convert a PHP array into a dictionary or list.
 * Indexed arrays are converted to lists.
 * Associative arrays are converted to dictionaries.
 * Sub-arrays are converted appropriately into either
 * dictionaries or lists.
 */
PHP_FUNCTION(php_getdns_util_convert_array)
{
    long tmpDictOrList = 0;
    zval *dictOrList = NULL, *phpArray = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &phpArray, &dictOrList) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert the array. */
    result = convert_array_internal(phpArray, &tmpDictOrList);
    ZVAL_LONG(dictOrList, tmpDictOrList);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to convert a getdns dictionary to a PHP array.
 */
PHP_FUNCTION(php_getdns_util_convert_dict)
{
    long phpDict = 0;
    zval *phpArray = NULL;
    getdns_dict *dict = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpDict, &phpArray) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters. */
    dict = (getdns_dict *) phpDict;
    convert_to_null(phpArray);
    result = convert_dict_internal(dict, phpArray);

    /* Return the result. */
    RETURN_LONG((long) result);
}

/**
 * Function to convert a getdns list to a PHP array.
 */
PHP_FUNCTION(php_getdns_util_convert_list)
{
    long phpList = 0;
    zval *phpArray = NULL;
    getdns_list *list = NULL;
    getdns_return_t result;

    /* Retrieve parameters. */
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "lz", &phpList, &phpArray) ==
	FAILURE) {
	RETURN_NULL();
    }

    /* Convert parameters. */
    list = (getdns_list *) phpList;
    convert_to_null(phpArray);
    result = convert_list_internal(list, phpArray);

    /* Return the result. */
    RETURN_LONG((long) result);
}
