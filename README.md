# oc_place2book_feedback
Dette modul lader ding biblioteker indhente feedback fra deltagere som har fået billet gennem place2book.

Der vil blive udsendt en email med et link til en valgt webform.
For at systemet kan generere de nødvendige feedback statestikker or det påkrævet at have et skjult felt med maskin navnet "event_nid"
på sin webformular.

Statestik siden kan automatisk generer pie charts og paginerede tabeller for "select"  og "textarea" felt typer på webformularen.

De kan tilgås gennem menu punktet: /admin/reports/oc_p2b_feedback

Feedback emails are sendt out after the events are unpublished and they have been marked for feedback collection via the node-create/edit form. It is required that the event is using p2b for ticket manageing and that the event is not passive.

<h2>note</h2>
When you activate the module it will create a webform to be use called "Arrangements feedback". You will still have to manualy select the webform to use under /admin/config/ding/place2book "PLACE2BOOK FEEDBACK SETTINGS" before the feedback system will work.

Once you have saved the selection , the module will take over the webform and style it + ensure it contains neccesary information for statistics to be generated.

<h3>wkhtmltopdf</h3>
For at printe pie diagrammer med er det nødvendigt at tilføje et delay på rendering ved hjælp af dette parameter: --javascript-delay 1000