<?php if ($pie_data != null || $bar_data != null) { ?>
    
    <div class="align-center" style="">
    <?php
    $pie_data  = isset($pie_data) && $pie_data != null ? $pie_data : $bar_data;
    foreach ($pie_data as $key => $value) { ?>
    
        <div id="<?php echo $key . "_container" ?>" style="min-width: 100%; height: 400px; max-width: 100%; margin: 0 auto"></div>
   
    <?php } ?>
    <div id="container_line" style="min-width: 310px; height: 400px; margin: 0 auto"></div>
    <script>
        jQuery(document).ready(function () {
            jQuery('.tablesorter').tablesorterPager({container: jQuery("#pager")});
        });

    <?php
    foreach ($pie_data as $key => $value) {
        ?>
            Highcharts.chart('<?php echo $key . "_container" ?>', {
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

    <?php } ?>

    </script>
    
    <script>
    <?php
    foreach ($bar_data as $key => $value) {
        ?>
    Highcharts.chart('<?php echo $key . "_container" ?>', {
            chart: {
                type: 'column'
            },
            title: {
                text: '<?php echo $key ?>'
            },
            subtitle: {
                text: ''
            },
            xAxis: {
                categories: [
                   'Tilfresheds værdier'
                ],
                crosshair: true
            },
            yAxis: {
                min: 0,
                title: {
                    text: 'tilfreshed'
                }
            },
            plotOptions: {
                column: {
                    pointPadding: 0.2,
                    borderWidth: 0
                }
            },
            series: <?php echo json_encode($value); ?>
        });
     <?php } ?>
    </script>
    <?php
        echo $textarea_data;
    ?>
   
    <div id="pager" class="pager">
        <img src="<?php echo "/" . drupal_get_path('module', 'oc_place2book_feedback') . "/img/first.png" ?>" class="first"/>
        <img src="<?php echo "/" . drupal_get_path('module', 'oc_place2book_feedback') . "/img/prev.png" ?>" class="prev"/>
        <input type="text" class="pagedisplay"/>
        <img src="<?php echo "/" . drupal_get_path('module', 'oc_place2book_feedback') . "/img/next.png" ?>" class="next"/>
        <img src="<?php echo "/" . drupal_get_path('module', 'oc_place2book_feedback') . "/img/last.png" ?>" class="last"/>
        <select class="pagesize">
            <option selected="selected"  value="10">10</option>
            <option value="20">20</option>
            <option value="30">30</option>
            <option  value="40">40</option>
        </select>
    </div>
    </div>
    <?php
} elseif ($pie_data == null) {
    ?>
    <h2>No data available</h2>
    <?php
}
?>
<a style="position:absolute;top:10px;right: 10px;" class="button" target="_blank" href="<?php echo request_uri() . "/pdf"; ?>">Print som pdf</a>

