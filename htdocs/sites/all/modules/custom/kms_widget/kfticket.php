<?php
	// Test if the cookie is already set, to avoid unnecessary contact to Kortforsyningen:
	$ticket = NULL;
	
	if (isset($_COOKIE['downloadticket']))
	{
		$ticket = $_COOKIE['downloadticket'];
	}
	// 
	// Replace the VisStedet login information with your own login
	// Fetch a ticket from Kortforsyningen, using your organization's login

	else
	{
        preg_match("/[^\.\/]+\.[^\.\/]+$/", $_SERVER['HTTP_HOST'], $matches);
        $domain = 'download.kortforsyningen.dk'; // $matches[0];

		$ticket = file_get_contents(
				"http://kortforsyningen.kms.dk/?request=GetTicket&login=nikam&password=KMS2012");
		setcookie("downloadticket", $ticket, time()+60*60*24, '/', $domain); 
	}
	// Print out the ticket in the HTML for easier reference and debugging:
	//echo "domain=$domain\n";
	//echo "kfticket= " . $_COOKIE['kfticket'];
?>