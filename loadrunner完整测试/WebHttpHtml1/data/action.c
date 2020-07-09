Action()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(57);

	lr_start_transaction("login_transaction");

	lr_rendezvous("login_zvous");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=zxy", ENDITEM, 
		"Name=password", "Value=123", ENDITEM, 
		"Name=login.x", "Value=76", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("login_transaction",LR_AUTO);

	lr_think_time(283);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t3.inf", 
		LAST);

	return 0;
}