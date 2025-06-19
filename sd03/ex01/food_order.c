/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:53:57 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/11 17:53:23 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	struct OrderConfirmation *confirmation;

	if (!request || !request->user_name || !request->order_details)
		return (0);
	if (!check_restaurant_status(request))
		confirmation = create_preorder_confirmation();
	else
		confirmation = create_standard_confirmation();
	if (!confirmation)
		return (0);
	send_confirmation_notification(confirmation);
	free(confirmation->confirmation_message);
	free(confirmation);
	free(request->user_name);
	free(request->order_details);
	return (1);
}