<?php
$completeName = "";
$tempStr = "";

function test_input($data)
{
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	if (!empty($_POST["completeName"]))
	{
		$completeName = test_input($_POST["completeName"]);
	}
	$spacePos = strpos($completeName, " ");
	$firstName = substr($completeName, 0, $spacePos);
	$remaining = substr($completeName, $spacePos + 1, strlen($completeName));
	$tempStr = "First name: " . $firstName . "\n";
	$tempStr = $tempStr . "It contains: " . strlen($firstName) . " letters.\n";
	$spacePos2 = strpos($remaining, " ");
	$middleName = substr($remaining, 0, $spacePos2);
	$tempStr = $tempStr . "Middle name: " . $middleName . "\n";
	$tempStr = $tempStr . "It contains: " . strlen($middleName) . " letters.\n";
	if ($spacePos2 == 0)
	{
		$lastName = substr($remaining, $spacePos2, strlen($remaining));
	}
	else
	{
		$lastName = substr($remaining, $spacePos2 + 1, strlen($remaining));
	}
	$tempStr = $tempStr . "Last name: " . $lastName . "\n";
	$tempStr = $tempStr . "It contains: " . strlen($lastName) . " letters.\n";
}
?>


<html>
<head>
<title>String Manipulation: PHP</title>

<script>

</script>

</head>

<body style="padding:30px;">
<h2> String Manipulation: PHP </h2>
Tyler Bruce <p>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
Name: <input type="text" name="completeName" value="<?php echo $completeName;?>">
<p>
<input type="submit" value="Extract Name">
<p>
<textarea name="results" Rows="8" Cols="50"><?php echo $tempStr;?></textarea>
</form>

</body>
</html>