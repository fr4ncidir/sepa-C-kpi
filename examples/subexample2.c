/*
 * subexample.c
 * 
 * Copyright 2017 Francesco Antoniazzi <francesco.antoniazzi@unibo.it>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/**
 * @brief Example of code used to make a subscription to SEPA
 * @file subexample.c
 * @author Francesco Antoniazzi <francesco.antoniazzi@unibo.it>
 * @date 12 Apr 2017
 * @example
 */
 
#define SEPA_LOGGER_ERROR
#include <stdio.h>
#include "../sepa_consumer.h"
#include "../sepa_secure.h"

// declare your handlers
void mySubscriptionNotification(sepaNode * added,int addedlen,sepaNode * removed,int removedlen);
void myUnsubscriptionNotification();

int main(int argc, char **argv) {
	// initialize subscriptions
	SEPA_subscription_params this_subscription = _initSubscription();
	int a;
	sClient authorizationData;
	
	authorizationData = registerClient("08:00:27:78:c5:4e","https://10.0.2.15:8443/oauth/register");
	fprintfSecureClientData(stdout,authorizationData);
	
	// initialize subscription client engine
	//sepa_subscriber_init();
	
	//// create subscriptions and set the respective handlers
	//sepa_subscription_builder("SELECT ?a ?b ?c WHERE {?a ?b ?c}",NULL,NULL,"ws://10.0.2.15:9000/sparql",&this_subscription);
	//sepa_setSubscriptionHandlers(mySubscriptionNotification,myUnsubscriptionNotification,&this_subscription);
	
	//// check if it is correct
	//fprintfSubscriptionParams(stdout,this_subscription);
	
	//// subscribe
	//kpSubscribe(&this_subscription);
	
	//// prompt user to stop
	//printf("insert a number to continue: "); scanf("%d",&a);
	
	//// unsubscribe
	//kpUnsubscribe(&this_subscription);
	
	//// close subscription client engine
	//sepa_subscriber_destroy();
	return 0;
}

// write your handlers
void mySubscriptionNotification(sepaNode * added,int addedlen,sepaNode * removed,int removedlen) {
	int i;
	printf("This is my subscription notification!\n\n");
	if (added!=NULL) {
		printf("Added %d items:\n",addedlen);
		fprintfSepaNodes(stdout,added,addedlen,"");
		freeSepaNodes(added,addedlen);
	}
	if (removed!=NULL) {
		printf("Removed %d items:\n",removedlen);
		fprintfSepaNodes(stdout,removed,removedlen,"");
		freeSepaNodes(removed,removedlen);
	}
	printf("\n");
}

void myUnsubscriptionNotification() {
	printf("This is an unsubscription notification!\n");
}