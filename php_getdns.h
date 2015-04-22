/**
 *
 * \file php_getdns.h
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

#ifndef PHP_GETDNS_H
#define PHP_GETDNS_H 1

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(getdns)
  int getdnsTestGlobal;
ZEND_END_MODULE_GLOBALS(getdns)

#ifdef ZTS
#define GETDNS_G(v) TSRMG(getdns_globals_id, zend_getdns_globals *, v)
#else
#define GETDNS_G(v) (getdns_globals.v)
#endif

/* Miscellaneous definitions. */

#define PHP_GETDNS_VERSION "0.3.0"
#define PHP_GETDNS_EXTNAME "getdns"

/* PHP environment setup functions. */

PHP_MINIT_FUNCTION(getdns);
PHP_MSHUTDOWN_FUNCTION(getdns);
PHP_RINIT_FUNCTION(getdns);
PHP_RSHUTDOWN_FUNCTION(getdns);
PHP_MINFO_FUNCTION(getdns);

/* PHP function declarations for getdns API functions. */

PHP_FUNCTION(php_getdns_address);
PHP_FUNCTION(php_getdns_address_sync);
PHP_FUNCTION(php_getdns_cancel_callback);
PHP_FUNCTION(php_getdns_context_create);
PHP_FUNCTION(php_getdns_context_destroy);
PHP_FUNCTION(php_getdns_context_detach_eventloop);
PHP_FUNCTION(php_getdns_context_get_api_information);
PHP_FUNCTION(php_getdns_context_get_append_name);
PHP_FUNCTION(php_getdns_context_get_dns_root_servers);
PHP_FUNCTION(php_getdns_context_get_dns_transport);
PHP_FUNCTION(php_getdns_context_get_dnssec_allowed_skew);
PHP_FUNCTION(php_getdns_context_get_dnssec_trust_anchors);
PHP_FUNCTION(php_getdns_context_get_edns_do_bit);
PHP_FUNCTION(php_getdns_context_get_edns_extended_rcode);
PHP_FUNCTION(php_getdns_context_get_edns_maximum_udp_payload_size);
PHP_FUNCTION(php_getdns_context_get_edns_version);
PHP_FUNCTION(php_getdns_context_get_follow_redirects);
PHP_FUNCTION(php_getdns_context_get_limit_outstanding_queries);
PHP_FUNCTION(php_getdns_context_get_namespaces);
PHP_FUNCTION(php_getdns_context_get_num_pending_requests);
PHP_FUNCTION(php_getdns_context_get_resolution_type);
PHP_FUNCTION(php_getdns_context_get_suffix);
PHP_FUNCTION(php_getdns_context_get_timeout);
PHP_FUNCTION(php_getdns_context_get_update_callback);
PHP_FUNCTION(php_getdns_context_get_upstream_recursive_servers);
PHP_FUNCTION(php_getdns_context_process_async);
PHP_FUNCTION(php_getdns_context_run);
PHP_FUNCTION(php_getdns_context_set_append_name);
PHP_FUNCTION(php_getdns_context_set_dns_root_servers);
PHP_FUNCTION(php_getdns_context_set_dns_transport);
PHP_FUNCTION(php_getdns_context_set_dnssec_allowed_skew);
PHP_FUNCTION(php_getdns_context_set_dnssec_trust_anchors);
PHP_FUNCTION(php_getdns_context_set_edns_do_bit);
PHP_FUNCTION(php_getdns_context_set_edns_extended_rcode);
PHP_FUNCTION(php_getdns_context_set_edns_maximum_udp_payload_size);
PHP_FUNCTION(php_getdns_context_set_edns_version);
PHP_FUNCTION(php_getdns_context_set_follow_redirects);
PHP_FUNCTION(php_getdns_context_set_limit_outstanding_queries);
PHP_FUNCTION(php_getdns_context_set_namespaces);
PHP_FUNCTION(php_getdns_context_set_resolution_type);
PHP_FUNCTION(php_getdns_context_set_return_dnssec_status);
PHP_FUNCTION(php_getdns_context_set_suffix);
PHP_FUNCTION(php_getdns_context_set_timeout);
PHP_FUNCTION(php_getdns_context_set_update_callback);
PHP_FUNCTION(php_getdns_context_set_upstream_recursive_servers);
PHP_FUNCTION(php_getdns_context_set_use_threads);
PHP_FUNCTION(php_getdns_convert_alabel_to_ulabel);
PHP_FUNCTION(php_getdns_convert_dns_name_to_fqdn);
PHP_FUNCTION(php_getdns_convert_fqdn_to_dns_name);
PHP_FUNCTION(php_getdns_convert_ulabel_to_alabel);
PHP_FUNCTION(php_getdns_dict_create);
PHP_FUNCTION(php_getdns_dict_create_with_context);
PHP_FUNCTION(php_getdns_dict_destroy);
PHP_FUNCTION(php_getdns_dict_get_bindata);
PHP_FUNCTION(php_getdns_dict_get_data_type);
PHP_FUNCTION(php_getdns_dict_get_dict);
PHP_FUNCTION(php_getdns_dict_get_int);
PHP_FUNCTION(php_getdns_dict_get_list);
PHP_FUNCTION(php_getdns_dict_get_names);
PHP_FUNCTION(php_getdns_dict_remove_name);
PHP_FUNCTION(php_getdns_dict_set_bindata);
PHP_FUNCTION(php_getdns_dict_set_dict);
PHP_FUNCTION(php_getdns_dict_set_int);
PHP_FUNCTION(php_getdns_dict_set_list);
PHP_FUNCTION(php_getdns_dict_util_get_string);
PHP_FUNCTION(php_getdns_dict_util_set_string);
PHP_FUNCTION(php_getdns_display_ip_address);
PHP_FUNCTION(php_getdns_general);
PHP_FUNCTION(php_getdns_general_sync);
PHP_FUNCTION(php_getdns_get_errorstr_by_id);
PHP_FUNCTION(php_getdns_hostname);
PHP_FUNCTION(php_getdns_hostname_sync);
PHP_FUNCTION(php_getdns_list_create);
PHP_FUNCTION(php_getdns_list_create_with_context);
PHP_FUNCTION(php_getdns_list_destroy);
PHP_FUNCTION(php_getdns_list_get_bindata);
PHP_FUNCTION(php_getdns_list_get_data_type);
PHP_FUNCTION(php_getdns_list_get_dict);
PHP_FUNCTION(php_getdns_list_get_int);
PHP_FUNCTION(php_getdns_list_get_length);
PHP_FUNCTION(php_getdns_list_get_list);
PHP_FUNCTION(php_getdns_list_set_bindata);
PHP_FUNCTION(php_getdns_list_set_dict);
PHP_FUNCTION(php_getdns_list_set_int);
PHP_FUNCTION(php_getdns_list_set_list);
PHP_FUNCTION(php_getdns_pretty_print_dict);
PHP_FUNCTION(php_getdns_pretty_print_list);
PHP_FUNCTION(php_getdns_print_json_dict);
PHP_FUNCTION(php_getdns_print_json_list);
PHP_FUNCTION(php_getdns_root_trust_anchor);
PHP_FUNCTION(php_getdns_service);
PHP_FUNCTION(php_getdns_service_sync);
PHP_FUNCTION(php_getdns_validate_dnssec);

extern zend_module_entry getdns_module_entry;
#define phpext_getdns_ptr &getdns_module_entry

#endif

