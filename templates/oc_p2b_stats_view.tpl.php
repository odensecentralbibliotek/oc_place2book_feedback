
<script src="http://code.highcharts.com/highcharts.js"></script>
<script src="https://code.highcharts.com/modules/exporting.js"></script>
<script src="http://tablesorter.com/addons/pager/jquery.tablesorter.pager.js"></script>
<form>
    <select name="oc_p2b_feedback_select_node">
        <option value=""></option>
        <?php foreach($selectable_nodes as $node){ ?>
        <option <?php if($node->nid == $selected_node) {echo "selected='selected'";} ?> value="<?php echo $node->nid; ?>"><?php echo $node->title; ?></option>
        <?php } ?>
    </select>
    <input type="submit" value="Vælg">
</form>
<?php if($pie_data != null && $selected_node != null){?>
<?php 
    foreach($pie_data as $key => $value){ ?>
<div id="<?php echo $key."_container" ?>" style="min-width: 310px; height: 400px; max-width: 100%; margin: 0 auto"></div>
<?php } ?>
<style>
    .pager
    {
        position: initial !important;
    }
</style>
<script>
    jQuery(document).ready(function() {
        jQuery('.tablesorter').tablesorterPager({container: jQuery("#pager")});
    });
    
    <?php 
    foreach($pie_data as $key => $value)
    {?>
        Highcharts.chart('<?php echo $key."_container" ?>', {
    chart: {
        plotBackgroundColor: null,
        plotBorderWidth: null,
        plotShadow: false,
        type: 'pie'
    },
    title: {
        text: '<?php echo $key ?>'
    },
    tooltip: {
        pointFormat: '{series.name}: <b>{point.percentage:.1f}%</b>'
    },
    plotOptions: {
        pie: {
            allowPointSelect: true,
            cursor: 'pointer',
            dataLabels: {
                enabled: true,
                format: '<b>{point.name}</b>: {point.percentage:.1f} %',
                style: {
                    color: (Highcharts.theme && Highcharts.theme.contrastTextColor) || 'black'
                }
            }
        }
    },
    series: [{
        name: 'Brands',
        colorByPoint: true,
        data: <?php echo json_encode($value) ?>
    }]
});
        
    <?php }?>
    
</script>
<?php
echo $textarea_data;
?>
<div id="pager" class="pager">
		<img src="../addons/pager/icons/first.png" class="first"/>
		<img src="../addons/pager/icons/prev.png" class="prev"/>
		<input type="text" class="pagedisplay"/>
		<img src="../addons/pager/icons/next.png" class="next"/>
		<img src="../addons/pager/icons/last.png" class="last"/>
		<select class="pagesize">
			<option selected="selected"  value="10">10</option>
			<option value="20">20</option>
			<option value="30">30</option>
			<option  value="40">40</option>
		</select>
</div>
<?php
}elseif($pie_data == null && $selected_node != null)
{
?>
<h2>No data available</h2>
<?php
}elseif($selected_node == null)
{
    echo "<h1>Select a event to get feedback</h1>";
}
?>

