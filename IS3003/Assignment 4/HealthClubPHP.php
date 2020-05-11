<?php
$tax = 0;
$total = 0;
$membership = "gold";
$tennis = "no";
$racquetball = "no";
$golf = "no";
$cc = "no";
$pt = "no";
$sp = "no";

function test_input($data)
{
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}
if ( $_SERVER["REQUEST_METHOD"] == "POST")
{
	if (!empty($_POST["tax"]))
	{
		$tax = test_input($_POST["tax"]);
	}
	if (!empty($_POST["membership"]))
	{
		$membership = test_input($_POST["membership"]);
	}
	if ($membership == "basic")
	{ 
		$total = 80;
	}
	elseif ($membership == "plat") 
	{
		$total = 100;
	}
	else
	{
		$total = 120;
	}
	if (isset($_POST["tennis"]))
	{
		$tennis = "yes";
		$total = $total + 15;
	}
	if (isset($_POST["racquetball"]))
	{
		$racquetball = "yes";
		$total = $total + 20;
	}
	if (isset($_POST["golf"]))
	{
		$golf = "yes";
		$total = $total + 25;
	}
	if (isset($_POST["cc"]))
	{
		$cc = "yes";
		$total = $total + 100;
	}
	if (isset($_POST["pt"]))
	{
		$pt = "yes";
		$total = $total + 120;
	}
	if (isset($_POST["sp"]))
	{
		$sp = "yes";
		$total = $total + 20;
	}
	$total = $total + $total * $tax;
	$total = round($total, 2);
	
}

?>

<h2> PHP Health Calculator</h2>
James "Tyler" Bruce <p>


<form id="form1" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>  ">
<div style="float:left; width:130px;background-color:tomato;">
<dl>
<dt>Membership
<dt><input type="radio" name="membership" onchange="reloadForm()" <?php if (isset($membership) && $membership=="basic") echo "checked";?> value="basic">Basic
<dt><input type="radio" name="membership" onchange="reloadForm()" <?php if (isset($membership) && $membership=="plat") echo "checked";?> value="plat">Platinum
<dt><input type="radio" name="membership" onchange="reloadForm()" <?php if (isset($membership) && $membership=="gold") echo "checked";?> value="gold">Gold
</dl>
</div>
<div style="float:left; width:160px;background-color:lightgreen;">
<dl>
<dt> Additional Charges(1)
<dt><input type="checkbox" name="tennis" onchange="reloadForm()" <?php if (isset($tennis) && $tennis=="yes") echo "checked";?>> Tennis 
<dt><input type="checkbox" name="racquetball" onchange="reloadForm()" <?php if (isset($racquetball) && $racquetball=="yes") echo "checked";?>> Racquetball 
<dt><input type="checkbox" name="golf" onchange="reloadForm()" <?php if (isset($golf) && $golf=="yes") echo "checked";?>> Golf
</dl>
</div>
<div style="float:left; width:160px;background-color:lightblue;">
<dl>
<dt> Additional Charges(2)
<dt><input type="checkbox" name="cc" onchange="reloadForm()" <?php if (isset($cc) && $cc=="yes") echo "checked";?>> Child Care
<dt><input type="checkbox" name="pt" onchange="reloadForm()" <?php if (isset($pt) && $pt=="yes") echo "checked";?>> Personal Trainer 
<dt><input type="checkbox" name="sp" onchange="reloadForm()" <?php if (isset($sp) && $sp=="yes") echo "checked";?>> Swimming Pool
</dl>
</div>
<div style="clear:both">&nbsp;</div>
<div style="float:left; width:150px;background-color:yellow;">
<dl> 
<dt><button type="submit" value="Calculate Total"> Calculate Total 
</dl>
</div>
<div style="float:left; width:210px;background-color:DodgerBlue;">
<dl>
<dt>Tax: <input type="text" name="tax" value="<?php echo $tax;?>" size="10">
<dt>Total: <input type="text" name="total" value="<?php echo $total;?>" size="10">
</dl>
</div>

<script>
function reloadForm()
{
	document.getElementById("form1").submit();
}
</script>
</form>