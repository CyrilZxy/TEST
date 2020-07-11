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

	lr_think_time(5);

	lr_start_transaction("login_transaction");

	lr_rendezvous("login_zvous");

	web_reg_find("Search=Body",
		"Text=Welcome, <b>{username}</b>, to the Web Tours reservation pages.","SaveCount=reservation_Count",
		LAST);

/*Correlation comment - Do not change!  Original value='{username}' Name ='CorrelationParameter' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter",
		"LB=blockquote>Welcome, <b>",
		"RB=<",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login.pl*",
		"NotFound=warning" ,
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=usern" 
		"ame", "Value={username}", ENDITEM,
		"Name=password", "Value=12" 
		"3", ENDITEM,
		"Name=login.x", "Value=76", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);



	lr_log_message("enter message here");
	lr_output_message("username=%s",lr_eval_string("{username}"));

	
	lr_end_transaction("login_transaction",LR_AUTO);

	lr_think_time(5);


	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t3.inf", 
		LAST);

	return 0;
}