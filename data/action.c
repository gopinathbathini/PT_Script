Action()
{

	web_add_auto_header("Accept-Language", 
		"en-GB,en;q=0.9");

	web_url("pets.shaft.com", 
		"URL=http://pets.shaft.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	lr_think_time(6);

	lr_start_transaction("FindOwner");

	web_url("Find owners", 
		"URL=http://pets.shaft.com/owners/find", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("FindOwner",LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("AddOwner");

	web_url("Add Owner", 
		"URL=http://pets.shaft.com/owners/new", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/find", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("AddOwner",LR_AUTO);

	lr_start_transaction("Give_Details");

	web_submit_data("new", 
		"Action=http://pets.shaft.com/owners/new", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/new", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=allu", ENDITEM, 
		"Name=lastName", "Value=arjun", ENDITEM, 
		"Name=address", "Value=jublihills", ENDITEM, 
		"Name=city", "Value=hyd", ENDITEM, 
		"Name=telephone", "Value=98489377342", ENDITEM, 
		LAST);

	web_submit_data("new_2", 
		"Action=http://pets.shaft.com/owners/new", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/new", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=allu", ENDITEM, 
		"Name=lastName", "Value=arjun", ENDITEM, 
		"Name=address", "Value=jublihills", ENDITEM, 
		"Name=city", "Value=hyd", ENDITEM, 
		"Name=telephone", "Value=984893773", ENDITEM, 
		LAST);

	lr_end_transaction("Give_Details",LR_AUTO);

	return 0;
}