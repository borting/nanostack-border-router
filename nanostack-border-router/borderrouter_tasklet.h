/*
 * Copyright (c) 2016 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BORDERROUTER_TASKLET_H
#define BORDERROUTER_TASKLET_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Border router status code returned in callback.
 */
typedef enum {
  BORDER_ROUTER_CONNECTED = 0,  /*<! backhaul and 6lowpan interface are ready */
  BORDER_ROUTER_DISCONNECTED,	/*<! disconnected from network  */
  BORDER_ROUTER_BACKHAUL_BOOTSTRAP_FAILED,  /*<! backhaul interface bootstrap failed */
  BORDER_ROUTER_BACKHAUL_INTERFACE_DOWN,    /*<! backhaul interface down */
  BORDER_ROUTER_6LOWPAN_BOOTSTRAP_FAILED,   /*<! 6lowpan interface bootstrap failed */
  BORDER_ROUTER_6LOWPAN_INTERFACE_DOWN	    /*<! 6lowpan interface down */
} border_router_status_t;

typedef void (*border_router_handler_t)(border_router_status_t);

/**
 * Initializes the backhaul driver. MUST be implemented by the application.
 */
void backhaul_driver_init(void (*backhaul_driver_status_cb)(uint8_t, int8_t));

/**
 * Initializes the border router module: loads configuration and
 * initiates bootstrap for the RF 6LoWPAN and backhaul interfaces.
 */
void border_router_start(border_router_handler_t callback);

#ifdef __cplusplus
}
#endif

#endif /* BORDERROUTER_TASKLET_H */
