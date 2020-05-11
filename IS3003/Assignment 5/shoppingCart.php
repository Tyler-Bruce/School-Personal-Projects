<?php
$imgFileName = "";
$quantity = 1;
$tax = 0;
$price = 0;

function test_input($data)
{
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	if(!empty($_POST["price"]))
	{
		$price = test_input($_POST["price"]);
	}
	
	if(!empty($_POST["imgFileName"]))
	{
		$imgFileName = test_input($_POST["imgFileName"]);
	}
	
	if(!empty($_POST["quantity"]))
	{
		$quantity = test_input($_POST["quantity"]);
	}
	
	if (!empty($_POST["tax"]))
	{
		$tax = test_input($_POST["tax"]);
	}
	
	$price = (($price) + ($tax * $price)) * $quantity;
	$price = round($price,2);
	
}
	
?>


<body style="padding:30px;">

<h2> Shopping Cart </h2>

<form method="post" name="shoppingCart" id="shoppingCart"
	action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">

Total: <?php echo '$' . $price;?>
<p>

<?php if ($imgFileName != "")
	echo "<img src=\"$imgFileName\" style=\"max-height:125px; max-width:125px;\" > ";
?>

<p>

Quantity: <input type="text" name="quantity" value="<?php echo $quantity;?>" size="10">

<p>

Tax: <input type="text" name="tax" value="<?php echo $tax;?>" size="10">

<p>

<input type="hidden" name="price" value="<?php echo $price;?>">
<input type="hidden" name="imgFileName" value="<?php echo $imgFileName;?>">

<input type="submit" value="Recalculate Order">
</form>


</body>
