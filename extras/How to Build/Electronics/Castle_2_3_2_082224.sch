<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="57" name="tCAD" color="7" fill="1" visible="no" active="no"/>
<layer number="59" name="tCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="60" name="bCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Patch_Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="yes" active="yes"/>
<layer number="103" name="Stiffner" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="7" fill="1" visible="yes" active="yes"/>
<layer number="105" name="Beschreib" color="7" fill="1" visible="yes" active="yes"/>
<layer number="106" name="BGA-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="107" name="BD-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="108" name="tBridges" color="7" fill="1" visible="yes" active="yes"/>
<layer number="109" name="tBPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="110" name="bBPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="111" name="MPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="112" name="tSilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="113" name="ReferenceLS" color="7" fill="1" visible="yes" active="yes"/>
<layer number="114" name="Badge_Outline" color="7" fill="1" visible="no" active="yes"/>
<layer number="115" name="ReferenceISLANDS" color="7" fill="1" visible="no" active="yes"/>
<layer number="116" name="Patch_BOT" color="7" fill="1" visible="yes" active="yes"/>
<layer number="118" name="Rect_Pads" color="7" fill="1" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="123" name="tTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="124" name="bTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="126" name="_bNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="127" name="_tValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="128" name="_bValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="129" name="Mask" color="7" fill="1" visible="yes" active="yes"/>
<layer number="131" name="tAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="132" name="bAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="yes" active="yes"/>
<layer number="150" name="Notes" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="152" name="_bDocu" color="7" fill="1" visible="yes" active="yes"/>
<layer number="153" name="FabDoc1" color="7" fill="1" visible="yes" active="yes"/>
<layer number="154" name="FabDoc2" color="7" fill="1" visible="yes" active="yes"/>
<layer number="155" name="FabDoc3" color="7" fill="1" visible="yes" active="yes"/>
<layer number="199" name="Contour" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="201" name="201bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="202" name="202bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="203" name="203bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="204" name="204bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="205" name="205bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="207" name="207bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="208" name="208bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="217" name="217bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="218" name="218bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="219" name="219bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="220" name="220bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="221" name="221bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="222" name="222bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="223" name="223bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="224" name="224bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="225" name="225bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="226" name="226bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="227" name="227bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="228" name="228bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="229" name="229bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="230" name="230bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="231" name="Eagle3D_PG1" color="7" fill="1" visible="yes" active="yes"/>
<layer number="232" name="Eagle3D_PG2" color="7" fill="1" visible="yes" active="yes"/>
<layer number="233" name="Eagle3D_PG3" color="7" fill="1" visible="yes" active="yes"/>
<layer number="248" name="Housing" color="7" fill="1" visible="yes" active="yes"/>
<layer number="249" name="Edge" color="7" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="7" fill="1" visible="yes" active="yes"/>
<layer number="251" name="SMDround" color="7" fill="1" visible="yes" active="yes"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
<layer number="255" name="routoute" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="adafruit">
<packages>
<package name="FEATHERWING">
<description>FlipFeather</description>
<hole x="48.26" y="20.32" drill="2.54"/>
<hole x="48.26" y="2.54" drill="2.54"/>
<pad name="P$1" x="2.54" y="20.32" drill="2.5" diameter="3.81"/>
<pad name="P$2" x="2.54" y="2.54" drill="2.5" diameter="3.81"/>
<pad name="28" x="16.51" y="1.27" drill="1" diameter="1.778"/>
<pad name="27" x="19.05" y="1.27" drill="1" diameter="1.778"/>
<pad name="26" x="21.59" y="1.27" drill="1" diameter="1.778"/>
<pad name="25" x="24.13" y="1.27" drill="1" diameter="1.778"/>
<pad name="24" x="26.67" y="1.27" drill="1" diameter="1.778"/>
<pad name="23" x="29.21" y="1.27" drill="1" diameter="1.778"/>
<pad name="22" x="31.75" y="1.27" drill="1" diameter="1.778"/>
<pad name="21" x="34.29" y="1.27" drill="1" diameter="1.778"/>
<pad name="20" x="36.83" y="1.27" drill="1" diameter="1.778"/>
<pad name="19" x="39.37" y="1.27" drill="1" diameter="1.778"/>
<pad name="18" x="41.91" y="1.27" drill="1" diameter="1.778"/>
<pad name="17" x="44.45" y="1.27" drill="1" diameter="1.778"/>
<pad name="5" x="16.51" y="21.59" drill="1" diameter="1.778"/>
<pad name="6" x="19.05" y="21.59" drill="1" diameter="1.778"/>
<pad name="7" x="21.59" y="21.59" drill="1" diameter="1.778"/>
<pad name="8" x="24.13" y="21.59" drill="1" diameter="1.778"/>
<pad name="9" x="26.67" y="21.59" drill="1" diameter="1.778"/>
<pad name="10" x="29.21" y="21.59" drill="1" diameter="1.778"/>
<pad name="11" x="31.75" y="21.59" drill="1" diameter="1.778"/>
<pad name="12" x="34.29" y="21.59" drill="1" diameter="1.778"/>
<pad name="13" x="36.83" y="21.59" drill="1" diameter="1.778"/>
<pad name="14" x="39.37" y="21.59" drill="1" diameter="1.778"/>
<pad name="15" x="41.91" y="21.59" drill="1" diameter="1.778"/>
<pad name="16" x="44.45" y="21.59" drill="1" diameter="1.778"/>
<pad name="4" x="13.97" y="21.59" drill="1" diameter="1.778"/>
<pad name="3" x="11.43" y="21.59" drill="1" diameter="1.778"/>
<pad name="2" x="8.89" y="21.59" drill="1" diameter="1.778"/>
<pad name="1" x="6.35" y="21.59" drill="1" diameter="1.778"/>
</package>
<package name="FEATHERWING_DIM">
<hole x="48.26" y="20.32" drill="2.54"/>
<hole x="48.26" y="2.54" drill="2.54"/>
<pad name="P$1" x="2.54" y="20.32" drill="2.5" diameter="3.81"/>
<pad name="P$2" x="2.54" y="2.54" drill="2.5" diameter="3.81"/>
<pad name="28" x="16.51" y="21.59" drill="1" diameter="1.778"/>
<pad name="27" x="19.05" y="21.59" drill="1" diameter="1.778"/>
<pad name="26" x="21.59" y="21.59" drill="1" diameter="1.778"/>
<pad name="25" x="24.13" y="21.59" drill="1" diameter="1.778"/>
<pad name="24" x="26.67" y="21.59" drill="1" diameter="1.778"/>
<pad name="23" x="29.21" y="21.59" drill="1" diameter="1.778"/>
<pad name="22" x="31.75" y="21.59" drill="1" diameter="1.778"/>
<pad name="21" x="34.29" y="21.59" drill="1" diameter="1.778"/>
<pad name="20" x="36.83" y="21.59" drill="1" diameter="1.778"/>
<pad name="19" x="39.37" y="21.59" drill="1" diameter="1.778"/>
<pad name="18" x="41.91" y="21.59" drill="1" diameter="1.778"/>
<pad name="17" x="44.45" y="21.59" drill="1" diameter="1.778"/>
<pad name="5" x="16.51" y="1.27" drill="1" diameter="1.778"/>
<pad name="6" x="19.05" y="1.27" drill="1" diameter="1.778"/>
<pad name="7" x="21.59" y="1.27" drill="1" diameter="1.778"/>
<pad name="8" x="24.13" y="1.27" drill="1" diameter="1.778"/>
<pad name="9" x="26.67" y="1.27" drill="1" diameter="1.778"/>
<pad name="10" x="29.21" y="1.27" drill="1" diameter="1.778"/>
<pad name="11" x="31.75" y="1.27" drill="1" diameter="1.778"/>
<pad name="12" x="34.29" y="1.27" drill="1" diameter="1.778"/>
<pad name="13" x="36.83" y="1.27" drill="1" diameter="1.778"/>
<pad name="14" x="39.37" y="1.27" drill="1" diameter="1.778"/>
<pad name="15" x="41.91" y="1.27" drill="1" diameter="1.778"/>
<pad name="16" x="44.45" y="1.27" drill="1" diameter="1.778"/>
<pad name="4" x="13.97" y="1.27" drill="1" diameter="1.778"/>
<pad name="3" x="11.43" y="1.27" drill="1" diameter="1.778"/>
<pad name="2" x="8.89" y="1.27" drill="1" diameter="1.778"/>
<pad name="1" x="6.35" y="1.27" drill="1" diameter="1.778"/>
</package>
<package name="1X09-BIG">
<wire x1="-11.43" y1="1.27" x2="11.43" y2="1.27" width="0.127" layer="21"/>
<wire x1="11.43" y1="1.27" x2="11.43" y2="-1.27" width="0.127" layer="21"/>
<wire x1="11.43" y1="-1.27" x2="-11.43" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-1.27" x2="-11.43" y2="1.27" width="0.127" layer="21"/>
<pad name="1" x="-10.16" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="2" x="-7.62" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="3" x="-5.08" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="4" x="-2.54" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="5" x="0" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="6" x="2.54" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="7" x="5.08" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="8" x="7.62" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="9" x="10.16" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<text x="-10.2362" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="-5.334" y1="-0.254" x2="-4.826" y2="0.254" layer="51"/>
<rectangle x1="-7.874" y1="-0.254" x2="-7.366" y2="0.254" layer="51"/>
<rectangle x1="-10.414" y1="-0.254" x2="-9.906" y2="0.254" layer="51"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51"/>
<rectangle x1="9.906" y1="-0.254" x2="10.414" y2="0.254" layer="51"/>
</package>
<package name="1X06">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-0.635" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-6.35" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06-CLEAN">
<pad name="1" x="-6.35" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06-CLEANBIG">
<pad name="1" x="-6.35" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06-BIG">
<wire x1="-7.62" y1="1.27" x2="7.62" y2="1.27" width="0.127" layer="21"/>
<wire x1="7.62" y1="1.27" x2="7.62" y2="-1.27" width="0.127" layer="21"/>
<wire x1="7.62" y1="-1.27" x2="-7.62" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-1.27" x2="-7.62" y2="1.27" width="0.127" layer="21"/>
<pad name="1" x="-6.35" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06-BIGLOCK">
<wire x1="-7.62" y1="1.27" x2="7.62" y2="1.27" width="0.127" layer="21"/>
<wire x1="7.62" y1="1.27" x2="7.62" y2="-1.27" width="0.127" layer="21"/>
<wire x1="7.62" y1="-1.27" x2="-7.62" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-1.27" x2="-7.62" y2="1.27" width="0.127" layer="21"/>
<pad name="1" x="-6.35" y="0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="2" x="-3.81" y="-0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="-0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="-0.127" drill="1.016" diameter="1.778" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06-3.5MM">
<wire x1="-10.5" y1="3.4" x2="-10.5" y2="-2.5" width="0.127" layer="21"/>
<wire x1="-10.5" y1="-2.5" x2="-10.5" y2="-3.6" width="0.127" layer="21"/>
<wire x1="-10.5" y1="-3.6" x2="10.5" y2="-3.6" width="0.127" layer="21"/>
<wire x1="10.5" y1="-3.6" x2="10.5" y2="-2.5" width="0.127" layer="21"/>
<wire x1="10.5" y1="-2.5" x2="10.5" y2="3.4" width="0.127" layer="21"/>
<wire x1="10.5" y1="3.4" x2="-10.5" y2="3.4" width="0.127" layer="21"/>
<wire x1="-10.5" y1="-2.5" x2="10.5" y2="-2.5" width="0.127" layer="21"/>
<pad name="5" x="5.25" y="0" drill="1" diameter="2.1844"/>
<pad name="4" x="1.75" y="0" drill="1" diameter="2.1844"/>
<pad name="3" x="-1.75" y="0" drill="1" diameter="2.1844"/>
<pad name="2" x="-5.25" y="0" drill="1" diameter="2.1844"/>
<pad name="1" x="-8.75" y="0" drill="1" diameter="2.1844"/>
<pad name="6" x="8.75" y="0" drill="1" diameter="2.1844"/>
<text x="7.87" y="-5.81" size="1.27" layer="25" rot="R180">&gt;NAME</text>
</package>
<package name="1X01">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" diameter="1.9304" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
<package name="1X01-CLEANBIG">
<pad name="1" x="0" y="0" drill="1.016" diameter="1.778"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="1X1-BIGPOGO">
<pad name="P$1" x="0" y="0" drill="1.4" diameter="2.54" shape="long"/>
</package>
</packages>
<symbols>
<symbol name="MICROSHIELD">
<wire x1="0" y1="33.02" x2="0" y2="22.86" width="0.254" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="12.7" width="0.254" layer="94"/>
<wire x1="0" y1="12.7" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="48.26" y2="0" width="0.254" layer="94"/>
<wire x1="48.26" y1="0" x2="48.26" y2="33.02" width="0.254" layer="94"/>
<wire x1="48.26" y1="33.02" x2="12.7" y2="33.02" width="0.254" layer="94"/>
<pin name="!RESET" x="5.08" y="-5.08" length="middle" direction="in" rot="R90"/>
<pin name="3V" x="7.62" y="-5.08" length="middle" direction="sup" rot="R90"/>
<pin name="AREF" x="10.16" y="-5.08" length="middle" direction="pas" rot="R90"/>
<pin name="GND" x="12.7" y="-5.08" length="middle" direction="pwr" rot="R90"/>
<pin name="GPIOA0" x="15.24" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOA1" x="17.78" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOA2" x="20.32" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOA3" x="22.86" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOA4" x="25.4" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOA5" x="27.94" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOSCK" x="30.48" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOMOSI" x="33.02" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOMISO" x="35.56" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIORX" x="38.1" y="-5.08" length="middle" rot="R90"/>
<pin name="GPIOTX" x="40.64" y="-5.08" length="middle" rot="R90"/>
<pin name="NC" x="43.18" y="-5.08" length="middle" direction="pas" rot="R90"/>
<pin name="GPIOSDA" x="43.18" y="38.1" length="middle" rot="R270"/>
<pin name="GPIOSCL" x="40.64" y="38.1" length="middle" rot="R270"/>
<circle x="45.72" y="30.48" radius="1.27" width="0.254" layer="94"/>
<circle x="45.72" y="2.54" radius="1.27" width="0.254" layer="94"/>
<pin name="GPIO5" x="38.1" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO9" x="33.02" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO6" x="35.56" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO10" x="30.48" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO11" x="27.94" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO12" x="25.4" y="38.1" length="middle" rot="R270"/>
<pin name="GPIO13" x="22.86" y="38.1" length="middle" rot="R270"/>
<pin name="EN" x="17.78" y="38.1" length="middle" direction="pas" rot="R270"/>
<pin name="USB" x="20.32" y="38.1" length="middle" direction="sup" rot="R270"/>
<pin name="VBAT" x="15.24" y="38.1" length="middle" direction="sup" rot="R270"/>
<wire x1="12.7" y1="33.02" x2="5.08" y2="33.02" width="0.254" layer="94"/>
<wire x1="5.08" y1="33.02" x2="0" y2="33.02" width="0.254" layer="94"/>
<wire x1="5.08" y1="33.02" x2="5.08" y2="25.4" width="0.254" layer="94"/>
<wire x1="5.08" y1="25.4" x2="7.62" y2="25.4" width="0.254" layer="94"/>
<wire x1="7.62" y1="25.4" x2="10.16" y2="25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="25.4" x2="12.7" y2="25.4" width="0.254" layer="94"/>
<wire x1="12.7" y1="25.4" x2="12.7" y2="33.02" width="0.254" layer="94"/>
<wire x1="7.62" y1="27.94" x2="7.62" y2="25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="27.94" x2="10.16" y2="25.4" width="0.254" layer="94"/>
<wire x1="0" y1="22.86" x2="5.08" y2="22.86" width="0.254" layer="94"/>
<wire x1="5.08" y1="22.86" x2="5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="0" y2="12.7" width="0.254" layer="94"/>
<circle x="2.54" y="2.54" radius="1.27" width="0.254" layer="94"/>
<circle x="2.54" y="30.48" radius="1.27" width="0.254" layer="94"/>
</symbol>
<symbol name="PINHD9">
<wire x1="-6.35" y1="-12.7" x2="1.27" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-12.7" x2="1.27" y2="12.7" width="0.4064" layer="94"/>
<wire x1="1.27" y1="12.7" x2="-6.35" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="12.7" x2="-6.35" y2="-12.7" width="0.4064" layer="94"/>
<text x="-6.35" y="13.335" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="7" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="9" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINHD6">
<wire x1="-6.35" y1="-7.62" x2="1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-7.62" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINHD1">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FEATHERWING" prefix="MS">
<description>featherwingflip</description>
<gates>
<gate name="G$1" symbol="MICROSHIELD" x="-25.4" y="-15.24"/>
</gates>
<devices>
<device name="" package="FEATHERWING">
<connects>
<connect gate="G$1" pin="!RESET" pad="1"/>
<connect gate="G$1" pin="3V" pad="2"/>
<connect gate="G$1" pin="AREF" pad="3"/>
<connect gate="G$1" pin="EN" pad="27"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="GPIO10" pad="22"/>
<connect gate="G$1" pin="GPIO11" pad="23"/>
<connect gate="G$1" pin="GPIO12" pad="24"/>
<connect gate="G$1" pin="GPIO13" pad="25"/>
<connect gate="G$1" pin="GPIO5" pad="19"/>
<connect gate="G$1" pin="GPIO6" pad="20"/>
<connect gate="G$1" pin="GPIO9" pad="21"/>
<connect gate="G$1" pin="GPIOA0" pad="5"/>
<connect gate="G$1" pin="GPIOA1" pad="6"/>
<connect gate="G$1" pin="GPIOA2" pad="7"/>
<connect gate="G$1" pin="GPIOA3" pad="8"/>
<connect gate="G$1" pin="GPIOA4" pad="9"/>
<connect gate="G$1" pin="GPIOA5" pad="10"/>
<connect gate="G$1" pin="GPIOMISO" pad="13"/>
<connect gate="G$1" pin="GPIOMOSI" pad="12"/>
<connect gate="G$1" pin="GPIORX" pad="14"/>
<connect gate="G$1" pin="GPIOSCK" pad="11"/>
<connect gate="G$1" pin="GPIOSCL" pad="18"/>
<connect gate="G$1" pin="GPIOSDA" pad="17"/>
<connect gate="G$1" pin="GPIOTX" pad="15"/>
<connect gate="G$1" pin="NC" pad="16"/>
<connect gate="G$1" pin="USB" pad="26"/>
<connect gate="G$1" pin="VBAT" pad="28"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_NODIM" package="FEATHERWING_DIM">
<connects>
<connect gate="G$1" pin="!RESET" pad="1"/>
<connect gate="G$1" pin="3V" pad="2"/>
<connect gate="G$1" pin="AREF" pad="3"/>
<connect gate="G$1" pin="EN" pad="27"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="GPIO10" pad="22"/>
<connect gate="G$1" pin="GPIO11" pad="23"/>
<connect gate="G$1" pin="GPIO12" pad="24"/>
<connect gate="G$1" pin="GPIO13" pad="25"/>
<connect gate="G$1" pin="GPIO5" pad="19"/>
<connect gate="G$1" pin="GPIO6" pad="20"/>
<connect gate="G$1" pin="GPIO9" pad="21"/>
<connect gate="G$1" pin="GPIOA0" pad="5"/>
<connect gate="G$1" pin="GPIOA1" pad="6"/>
<connect gate="G$1" pin="GPIOA2" pad="7"/>
<connect gate="G$1" pin="GPIOA3" pad="8"/>
<connect gate="G$1" pin="GPIOA4" pad="9"/>
<connect gate="G$1" pin="GPIOA5" pad="10"/>
<connect gate="G$1" pin="GPIOMISO" pad="13"/>
<connect gate="G$1" pin="GPIOMOSI" pad="12"/>
<connect gate="G$1" pin="GPIORX" pad="14"/>
<connect gate="G$1" pin="GPIOSCK" pad="11"/>
<connect gate="G$1" pin="GPIOSCL" pad="18"/>
<connect gate="G$1" pin="GPIOSDA" pad="17"/>
<connect gate="G$1" pin="GPIOTX" pad="15"/>
<connect gate="G$1" pin="NC" pad="16"/>
<connect gate="G$1" pin="USB" pad="26"/>
<connect gate="G$1" pin="VBAT" pad="28"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X9" prefix="JP" uservalue="yes">
<description>&lt;b&gt;Pin header 1x10 0.1" spacing&lt;/b&gt;
&lt;p&gt;
With round pins</description>
<gates>
<gate name="G$1" symbol="PINHD9" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X09-BIG">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X6" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD6" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="1X06">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="CLEAN" package="1X06-CLEAN">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="CB" package="1X06-CLEANBIG">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="B" package="1X06-BIG">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="LOCK" package="1X06-BIGLOCK">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-3.5MM" package="1X06-3.5MM">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X1" prefix="JP" uservalue="yes">
<description>&lt;b&gt;Pin header 1x1 for 0.1" spacing&lt;/b&gt;
&lt;p&gt;
With round pins</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="CB" package="1X01-CLEANBIG">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-BIGPOGO" package="1X1-BIGPOGO">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lstb" urn="urn:adsk.eagle:library:162">
<description>&lt;b&gt;Pin Headers&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
MA = male&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="MA04-1" urn="urn:adsk.eagle:footprint:8285/1" library_version="1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-5.08" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.223" y="-0.635" size="1.27" layer="21" ratio="10">1</text>
<text x="0.635" y="1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="5.334" y="-0.635" size="1.27" layer="21" ratio="10">4</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="MA04-1" urn="urn:adsk.eagle:package:8337/1" type="box" library_version="1">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="MA04-1"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MA04-1" urn="urn:adsk.eagle:symbol:8284/1" library_version="1">
<wire x1="3.81" y1="-7.62" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<text x="-1.27" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MA04-1" urn="urn:adsk.eagle:component:8375/1" prefix="SV" uservalue="yes" library_version="1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="MA04-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA04-1">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="1" pin="3" pad="3"/>
<connect gate="1" pin="4" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8337/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-PowerSymbols" urn="urn:adsk.eagle:library:530">
<description>&lt;h3&gt;SparkFun Power Symbols&lt;/h3&gt;
This library contains power, ground, and voltage-supply symbols.
&lt;br&gt;
&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is &lt;b&gt; the end user's responsibility&lt;/b&gt; to ensure correctness and suitablity for a given componet or application. 
&lt;br&gt;
&lt;br&gt;If you enjoy using this library, please buy one of our products at &lt;a href=" www.sparkfun.com"&gt;SparkFun.com&lt;/a&gt;.
&lt;br&gt;
&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; Creative Commons ShareAlike 4.0 International - https://creativecommons.org/licenses/by-sa/4.0/ 
&lt;br&gt;
&lt;br&gt;
You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
</packages>
<symbols>
<symbol name="DGND" urn="urn:adsk.eagle:symbol:39415/1" library_version="1">
<description>&lt;h3&gt;Digital Ground Supply&lt;/h3&gt;</description>
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
<text x="0" y="-0.254" size="1.778" layer="96" align="top-center">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:39439/1" prefix="GND" library_version="1">
<description>&lt;h3&gt;Ground Supply Symbol&lt;/h3&gt;
&lt;p&gt;Generic signal ground supply symbol.&lt;/p&gt;</description>
<gates>
<gate name="1" symbol="DGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="buttons">
<packages>
<package name="B3F-10XX">
<description>&lt;b&gt;OMRON SWITCH&lt;/b&gt;</description>
<wire x1="3.302" y1="-0.762" x2="3.048" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="3.302" y1="-0.762" x2="3.302" y2="0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="0.762" x2="3.302" y2="0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="1.016" x2="3.048" y2="2.54" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.762" x2="-3.048" y2="0.762" width="0.1524" layer="21"/>
<wire x1="-3.302" y1="0.762" x2="-3.302" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="-0.762" x2="-3.302" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="2.54" x2="2.54" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.54" y1="-3.048" x2="3.048" y2="-2.54" width="0.1524" layer="51"/>
<wire x1="3.048" y1="-2.54" x2="3.048" y2="-1.016" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="3.048" x2="-3.048" y2="2.54" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="2.54" x2="-3.048" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="-3.048" x2="-3.048" y2="-2.54" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="-2.54" x2="-3.048" y2="-1.016" width="0.1524" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="-1.27" width="0.0508" layer="51"/>
<wire x1="1.27" y1="-1.27" x2="-1.27" y2="-1.27" width="0.0508" layer="51"/>
<wire x1="1.27" y1="-1.27" x2="1.27" y2="1.27" width="0.0508" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="1.27" y2="1.27" width="0.0508" layer="51"/>
<wire x1="-1.27" y1="3.048" x2="-1.27" y2="2.794" width="0.0508" layer="21"/>
<wire x1="1.27" y1="2.794" x2="-1.27" y2="2.794" width="0.0508" layer="21"/>
<wire x1="1.27" y1="2.794" x2="1.27" y2="3.048" width="0.0508" layer="21"/>
<wire x1="1.143" y1="-2.794" x2="-1.27" y2="-2.794" width="0.0508" layer="21"/>
<wire x1="1.143" y1="-2.794" x2="1.143" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-1.27" y1="-2.794" x2="-1.27" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="2.54" y1="-3.048" x2="2.159" y2="-3.048" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="-3.048" x2="-2.159" y2="-3.048" width="0.1524" layer="51"/>
<wire x1="-2.159" y1="-3.048" x2="-1.27" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="3.048" x2="-2.159" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.54" y1="3.048" x2="2.159" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.159" y1="3.048" x2="1.27" y2="3.048" width="0.1524" layer="21"/>
<wire x1="1.27" y1="3.048" x2="-1.27" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="3.048" x2="-2.159" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-3.048" x2="1.143" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="1.143" y1="-3.048" x2="2.159" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-0.762" x2="3.048" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="3.048" y1="0.762" x2="3.048" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="-0.762" x2="-3.048" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="0.762" x2="-3.048" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-2.159" x2="1.27" y2="-2.159" width="0.1524" layer="51"/>
<wire x1="1.27" y1="2.286" x2="-1.27" y2="2.286" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="1.27" x2="-2.413" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="-0.508" x2="-2.413" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="0.508" x2="-2.159" y2="-0.381" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="1.778" width="0.1524" layer="21"/>
<circle x="-2.159" y="-2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="2.159" y="-2.032" radius="0.508" width="0.1524" layer="51"/>
<circle x="2.159" y="2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="-2.159" y="2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.635" width="0.0508" layer="51"/>
<circle x="0" y="0" radius="0.254" width="0.1524" layer="21"/>
<pad name="1" x="-3.2512" y="2.2606" drill="1.016" shape="long"/>
<pad name="3" x="-3.2512" y="-2.2606" drill="1.016" shape="long"/>
<pad name="2" x="3.2512" y="2.2606" drill="1.016" shape="long"/>
<pad name="4" x="3.2512" y="-2.2606" drill="1.016" shape="long"/>
<text x="-1.778" y="3.683" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="2.413" y="-3.175" size="1.016" layer="27" ratio="18" rot="R180">&gt;VALUE</text>
<text x="-4.318" y="1.651" size="1.27" layer="51" ratio="10">1</text>
<text x="3.556" y="1.524" size="1.27" layer="51" ratio="10">2</text>
<text x="-4.572" y="-2.794" size="1.27" layer="51" ratio="10">3</text>
<text x="3.556" y="-2.794" size="1.27" layer="51" ratio="10">4</text>
</package>
<package name="BT4.5X4.5">
<description>4.5 x 4.5 mm SMD button</description>
<wire x1="-2.25" y1="-2.25" x2="2.25" y2="-2.25" width="0.127" layer="21"/>
<wire x1="2.25" y1="-2.25" x2="2.25" y2="2.25" width="0.127" layer="21"/>
<wire x1="2.25" y1="2.25" x2="-2.25" y2="2.25" width="0.127" layer="21"/>
<wire x1="-2.25" y1="2.25" x2="-2.25" y2="-2.25" width="0.127" layer="21"/>
<circle x="0" y="0" radius="1.25" width="0.127" layer="21"/>
<smd name="P" x="-3.5" y="1.5" dx="1.5" dy="1.5" layer="1"/>
<smd name="P1" x="3.5" y="1.5" dx="1.5" dy="1.5" layer="1"/>
<smd name="S" x="-3.5" y="-1.5" dx="1.5" dy="1.5" layer="1"/>
<smd name="S1" x="3.5" y="-1.5" dx="1.5" dy="1.5" layer="1"/>
<text x="-2" y="2.5" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-2" y="3.75" size="1.016" layer="27" ratio="18">&gt;VALUE</text>
</package>
<package name="BT4X4">
<wire x1="-2.6" y1="2.6" x2="2.6" y2="2.6" width="0.127" layer="21"/>
<wire x1="2.6" y1="2.6" x2="2.6" y2="-2.6" width="0.127" layer="21"/>
<wire x1="2.6" y1="-2.6" x2="-2.6" y2="-2.6" width="0.127" layer="21"/>
<wire x1="-2.6" y1="-2.6" x2="-2.6" y2="2.6" width="0.127" layer="21"/>
<circle x="0" y="0" radius="1" width="0.127" layer="21"/>
<smd name="1" x="-1.8" y="3.2" dx="1.4" dy="1.4" layer="1"/>
<smd name="2" x="-1.8" y="-3.2" dx="1.4" dy="1.4" layer="1"/>
<smd name="3" x="1.8" y="3.2" dx="1.4" dy="1.4" layer="1"/>
<smd name="4" x="1.8" y="-3.2" dx="1.4" dy="1.4" layer="1"/>
<text x="-3.175" y="-2.54" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="3.81" y="-2.54" size="1.016" layer="27" ratio="18" rot="R90">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="TS2">
<wire x1="1.905" y1="0" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="1.905" y1="4.445" x2="1.905" y2="3.175" width="0.254" layer="94"/>
<wire x1="-1.905" y1="4.445" x2="-1.905" y2="3.175" width="0.254" layer="94"/>
<wire x1="1.905" y1="4.445" x2="0" y2="4.445" width="0.254" layer="94"/>
<wire x1="0" y1="4.445" x2="-1.905" y2="4.445" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="94"/>
<wire x1="0" y1="4.445" x2="0" y2="3.175" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="1.905" y2="1.27" width="0.254" layer="94"/>
<circle x="-2.54" y="0" radius="0.127" width="0.4064" layer="94"/>
<circle x="2.54" y="0" radius="0.127" width="0.4064" layer="94"/>
<text x="-2.54" y="6.35" size="1.778" layer="95">&gt;NAME</text>
<text x="3.175" y="3.81" size="1.778" layer="96">&gt;VALUE</text>
<pin name="P" x="-5.08" y="0" visible="pad" length="short" direction="pas" swaplevel="2"/>
<pin name="S" x="5.08" y="0" visible="pad" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="S1" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="P1" x="-5.08" y="-2.54" visible="pad" length="short" direction="pas" swaplevel="2"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="10-XX" prefix="SW" uservalue="yes">
<description>&lt;b&gt;OMRON SWITCH&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="TS2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="B3F-10XX">
<connects>
<connect gate="1" pin="P" pad="3"/>
<connect gate="1" pin="P1" pad="4"/>
<connect gate="1" pin="S" pad="1"/>
<connect gate="1" pin="S1" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-4.5SMD" package="BT4.5X4.5">
<connects>
<connect gate="1" pin="P" pad="P"/>
<connect gate="1" pin="P1" pad="P1"/>
<connect gate="1" pin="S" pad="S"/>
<connect gate="1" pin="S1" pad="S1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4X4SMD" package="BT4X4">
<connects>
<connect gate="1" pin="P" pad="2"/>
<connect gate="1" pin="P1" pad="1"/>
<connect gate="1" pin="S" pad="4"/>
<connect gate="1" pin="S1" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Mohamed's-library">
<packages>
<package name="LCA7XX">
<pad name="P$1" x="-5.08" y="2.54" drill="0.8" shape="long" rot="R180"/>
<pad name="P$6" x="3.81" y="2.54" drill="0.8" shape="long" rot="R180"/>
<pad name="P$2" x="-5.08" y="0" drill="0.8" shape="long" rot="R180"/>
<pad name="P$3" x="-5.08" y="-2.54" drill="0.8" shape="long" rot="R180"/>
<pad name="P$4" x="3.81" y="-2.54" drill="0.8" shape="long" rot="R180"/>
<pad name="P$5" x="3.81" y="0" drill="0.8" shape="long" rot="R180"/>
<text x="-3.81" y="5.08" size="1.27" layer="25">&gt;name</text>
<wire x1="-1.27" y1="3.81" x2="-3.556" y2="3.81" width="0.127" layer="21"/>
<wire x1="-3.556" y1="3.81" x2="-3.556" y2="-3.81" width="0.127" layer="21"/>
<wire x1="2.286" y1="3.81" x2="2.286" y2="-3.81" width="0.127" layer="21"/>
<wire x1="2.286" y1="-3.81" x2="-3.556" y2="-3.81" width="0.127" layer="21"/>
<wire x1="2.286" y1="3.81" x2="0" y2="3.81" width="0.127" layer="21"/>
<wire x1="-1.27" y1="3.81" x2="0" y2="3.81" width="0.127" layer="21" curve="180"/>
</package>
</packages>
<symbols>
<symbol name="LCA715">
<wire x1="15.24" y1="-5.08" x2="-7.62" y2="-5.08" width="0.254" layer="94"/>
<pin name="+CONTROL" x="-12.7" y="12.7" length="middle"/>
<pin name="-CONTROL" x="-12.7" y="5.08" length="middle"/>
<pin name="NC" x="-12.7" y="-2.54" length="middle"/>
<pin name="+LOAD" x="20.32" y="12.7" length="middle" rot="R180"/>
<pin name="-LOAD" x="20.32" y="5.08" length="middle" rot="R180"/>
<pin name="+LOAD2" x="20.32" y="-2.54" length="middle" rot="R180"/>
<wire x1="-7.62" y1="-5.08" x2="-7.62" y2="15.24" width="0.254" layer="94"/>
<wire x1="-7.62" y1="15.24" x2="15.24" y2="15.24" width="0.254" layer="94"/>
<wire x1="15.24" y1="15.24" x2="15.24" y2="-5.08" width="0.254" layer="94"/>
<text x="-5.334" y="18.542" size="1.778" layer="94">LCA715</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="LCA715S">
<gates>
<gate name="G$1" symbol="LCA715" x="-66.04" y="20.32"/>
</gates>
<devices>
<device name="" package="LCA7XX">
<connects>
<connect gate="G$1" pin="+CONTROL" pad="P$1"/>
<connect gate="G$1" pin="+LOAD" pad="P$6"/>
<connect gate="G$1" pin="+LOAD2" pad="P$4"/>
<connect gate="G$1" pin="-CONTROL" pad="P$2"/>
<connect gate="G$1" pin="-LOAD" pad="P$5"/>
<connect gate="G$1" pin="NC" pad="P$3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-molex" urn="urn:adsk.eagle:library:165">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="22-23-2021" library_version="2">
<description>&lt;b&gt;KK® 254 Solid Header, Vertical, with Friction Lock, 2 Circuits, Tin (Sn) Plating&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/022232021_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-2.54" y1="3.175" x2="2.54" y2="3.175" width="0.254" layer="21"/>
<wire x1="2.54" y1="3.175" x2="2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="-3.175" width="0.254" layer="21"/>
<wire x1="2.54" y1="-3.175" x2="-2.54" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-3.175" x2="-2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="-2.54" y2="3.175" width="0.254" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="2.54" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1" shape="long" rot="R90"/>
<text x="-2.54" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="22-23-2031" urn="urn:adsk.eagle:footprint:8078260/1" library_version="5">
<description>&lt;b&gt;KK® 254 Solid Header, Vertical, with Friction Lock, 3 Circuits, Tin (Sn) Plating&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/022232031_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-3.81" y1="3.175" x2="3.81" y2="3.175" width="0.254" layer="21"/>
<wire x1="3.81" y1="3.175" x2="3.81" y2="1.27" width="0.254" layer="21"/>
<wire x1="3.81" y1="1.27" x2="3.81" y2="-3.175" width="0.254" layer="21"/>
<wire x1="3.81" y1="-3.175" x2="-3.81" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-3.81" y1="-3.175" x2="-3.81" y2="1.27" width="0.254" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.81" y2="3.175" width="0.254" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="3.81" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-2.54" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="1" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="1" shape="long" rot="R90"/>
<text x="-3.81" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.81" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="22-23-2031" urn="urn:adsk.eagle:package:8078634/1" type="box" library_version="5">
<description>&lt;b&gt;KK® 254 Solid Header, Vertical, with Friction Lock, 3 Circuits, Tin (Sn) Plating&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/022232031_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<packageinstances>
<packageinstance name="22-23-2031"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MV@1" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M@1" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="MV" urn="urn:adsk.eagle:symbol:6783/2" library_version="5">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M" urn="urn:adsk.eagle:symbol:6785/2" library_version="5">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="22-23-2021" prefix="X" library_version="2">
<description>.100" (2.54mm) Center Header - 2 Pin</description>
<gates>
<gate name="-1" symbol="MV@1" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M@1" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2021">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2021" constant="no"/>
<attribute name="OC_FARNELL" value="1462926" constant="no"/>
<attribute name="OC_NEWARK" value="25C3832" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="22-23-2031" urn="urn:adsk.eagle:component:8078937/3" prefix="X" library_version="5">
<description>.100" (2.54mm) Center Header - 3 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2031">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8078634/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2031" constant="no"/>
<attribute name="OC_FARNELL" value="1462950" constant="no"/>
<attribute name="OC_NEWARK" value="30C0862" constant="no"/>
<attribute name="POPULARITY" value="35" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="MS2" library="adafruit" deviceset="FEATHERWING" device="_NODIM" value="FEATHERWING_NODIM"/>
<part name="SCREEN" library="adafruit" deviceset="PINHD-1X9" device=""/>
<part name="SERVO" library="con-lstb" library_urn="urn:adsk.eagle:library:162" deviceset="MA04-1" device="" package3d_urn="urn:adsk.eagle:package:8337/1"/>
<part name="OUTPUT" library="adafruit" deviceset="PINHD-1X6" device=""/>
<part name="MOUSERAT" library="con-lstb" library_urn="urn:adsk.eagle:library:162" deviceset="MA04-1" device="" package3d_urn="urn:adsk.eagle:package:8337/1"/>
<part name="EXTRAGND" library="adafruit" deviceset="PINHD-1X1" device="-BIGPOGO"/>
<part name="TOUCH_INPUT" library="adafruit" deviceset="PINHD-1X6" device=""/>
<part name="EXTRAGND1" library="adafruit" deviceset="PINHD-1X1" device="-BIGPOGO"/>
<part name="EXTRAGND2" library="adafruit" deviceset="PINHD-1X1" device="-BIGPOGO"/>
<part name="SW1" library="buttons" deviceset="10-XX" device=""/>
<part name="SW2" library="buttons" deviceset="10-XX" device=""/>
<part name="GND8" library="SparkFun-PowerSymbols" library_urn="urn:adsk.eagle:library:530" deviceset="GND" device=""/>
<part name="GND9" library="SparkFun-PowerSymbols" library_urn="urn:adsk.eagle:library:530" deviceset="GND" device=""/>
<part name="SW3" library="buttons" deviceset="10-XX" device=""/>
<part name="GND1" library="SparkFun-PowerSymbols" library_urn="urn:adsk.eagle:library:530" deviceset="GND" device=""/>
<part name="LCA715" library="Mohamed's-library" deviceset="LCA715S" device=""/>
<part name="X1" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2021" device=""/>
<part name="POWER" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2031" device="" package3d_urn="urn:adsk.eagle:package:8078634/1"/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="-83.82" y1="86.36" x2="2.54" y2="86.36" width="0.254" layer="94" style="longdash"/>
<wire x1="2.54" y1="86.36" x2="45.466" y2="86.36" width="0.254" layer="94" style="longdash"/>
<text x="53.34" y="119.38" size="1.778" layer="91">on/off switch</text>
</plain>
<instances>
<instance part="MS2" gate="G$1" x="22.86" y="95.25" smashed="yes" rot="R270"/>
<instance part="SCREEN" gate="G$1" x="-13.97" y="71.12" smashed="yes">
<attribute name="NAME" x="-20.32" y="84.455" size="1.778" layer="95"/>
<attribute name="VALUE" x="-20.32" y="55.88" size="1.778" layer="96"/>
</instance>
<instance part="SERVO" gate="1" x="26.67" y="25.4" smashed="yes">
<attribute name="VALUE" x="25.4" y="15.24" size="1.778" layer="96"/>
<attribute name="NAME" x="25.4" y="31.242" size="1.778" layer="95"/>
</instance>
<instance part="OUTPUT" gate="A" x="-13.97" y="29.21" smashed="yes">
<attribute name="NAME" x="-20.32" y="40.005" size="1.778" layer="95"/>
<attribute name="VALUE" x="-20.32" y="19.05" size="1.778" layer="96"/>
</instance>
<instance part="MOUSERAT" gate="1" x="50.8" y="26.67" smashed="yes">
<attribute name="VALUE" x="49.53" y="16.51" size="1.778" layer="96"/>
<attribute name="NAME" x="49.53" y="32.512" size="1.778" layer="95"/>
</instance>
<instance part="EXTRAGND" gate="G$1" x="15.24" y="5.08" smashed="yes">
<attribute name="VALUE" x="8.89" y="0" size="1.778" layer="96"/>
</instance>
<instance part="TOUCH_INPUT" gate="A" x="-39.37" y="29.21" smashed="yes">
<attribute name="NAME" x="-45.72" y="40.005" size="1.778" layer="95"/>
<attribute name="VALUE" x="-45.72" y="19.05" size="1.778" layer="96"/>
</instance>
<instance part="EXTRAGND1" gate="G$1" x="15.24" y="-2.54" smashed="yes">
<attribute name="VALUE" x="8.89" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="EXTRAGND2" gate="G$1" x="15.24" y="-10.16" smashed="yes">
<attribute name="VALUE" x="8.89" y="-15.24" size="1.778" layer="96"/>
</instance>
<instance part="SW1" gate="1" x="-55.88" y="106.68" smashed="yes">
<attribute name="NAME" x="-58.42" y="113.03" size="1.778" layer="95"/>
<attribute name="VALUE" x="-52.705" y="110.49" size="1.778" layer="96"/>
</instance>
<instance part="SW2" gate="1" x="-10.16" y="106.68" smashed="yes">
<attribute name="NAME" x="-12.7" y="113.03" size="1.778" layer="95"/>
<attribute name="VALUE" x="-6.985" y="110.49" size="1.778" layer="96"/>
</instance>
<instance part="GND8" gate="1" x="-48.26" y="93.98" smashed="yes">
<attribute name="VALUE" x="-48.26" y="93.726" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="GND9" gate="1" x="-2.54" y="93.98" smashed="yes">
<attribute name="VALUE" x="-2.54" y="93.726" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="SW3" gate="1" x="22.86" y="116.84" smashed="yes">
<attribute name="NAME" x="20.32" y="123.19" size="1.778" layer="95"/>
<attribute name="VALUE" x="26.035" y="120.65" size="1.778" layer="96"/>
</instance>
<instance part="GND1" gate="1" x="30.48" y="104.14" smashed="yes">
<attribute name="VALUE" x="30.48" y="103.886" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="LCA715" gate="G$1" x="-109.22" y="58.42" smashed="yes"/>
<instance part="X1" gate="-1" x="-109.22" y="104.14" smashed="yes">
<attribute name="NAME" x="-106.68" y="103.378" size="1.524" layer="95"/>
<attribute name="VALUE" x="-109.982" y="105.537" size="1.778" layer="96"/>
</instance>
<instance part="X1" gate="-2" x="-109.22" y="101.6" smashed="yes">
<attribute name="NAME" x="-106.68" y="100.838" size="1.524" layer="95"/>
</instance>
<instance part="POWER" gate="-1" x="53.34" y="114.3" smashed="yes">
<attribute name="NAME" x="55.88" y="113.538" size="1.524" layer="95"/>
<attribute name="VALUE" x="52.578" y="115.697" size="1.778" layer="96"/>
</instance>
<instance part="POWER" gate="-2" x="53.34" y="111.76" smashed="yes">
<attribute name="NAME" x="55.88" y="110.998" size="1.524" layer="95"/>
</instance>
<instance part="POWER" gate="-3" x="53.34" y="109.22" smashed="yes">
<attribute name="NAME" x="55.88" y="108.458" size="1.524" layer="95"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="MOUSERAT" gate="1" pin="4"/>
<wire x1="58.42" y1="29.21" x2="62.23" y2="29.21" width="0.1524" layer="91"/>
<label x="63.5" y="29.21" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SCREEN" gate="G$1" pin="7"/>
<wire x1="-16.51" y1="66.04" x2="-24.13" y2="66.04" width="0.1524" layer="91"/>
<label x="-26.67" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="TOUCH_INPUT" gate="A" pin="1"/>
<wire x1="-41.91" y1="36.83" x2="-49.53" y2="36.83" width="0.1524" layer="91"/>
<label x="-53.34" y="36.83" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SW1" gate="1" pin="S"/>
<wire x1="-50.8" y1="106.68" x2="-48.26" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="106.68" x2="-48.26" y2="104.14" width="0.1524" layer="91"/>
<pinref part="SW1" gate="1" pin="S1"/>
<wire x1="-48.26" y1="104.14" x2="-50.8" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="104.14" x2="-48.26" y2="96.52" width="0.1524" layer="91"/>
<junction x="-48.26" y="104.14"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SW2" gate="1" pin="S"/>
<wire x1="-5.08" y1="106.68" x2="-2.54" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="106.68" x2="-2.54" y2="104.14" width="0.1524" layer="91"/>
<pinref part="SW2" gate="1" pin="S1"/>
<wire x1="-2.54" y1="104.14" x2="-5.08" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="104.14" x2="-2.54" y2="96.52" width="0.1524" layer="91"/>
<junction x="-2.54" y="104.14"/>
<pinref part="GND9" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="MS2" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="82.55" x2="15.24" y2="82.55" width="0.1524" layer="91"/>
<wire x1="15.24" y1="82.55" x2="15.24" y2="83.82" width="0.1524" layer="91"/>
<label x="10.16" y="83.82" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="MS2" gate="G$1" pin="NC"/>
<wire x1="17.78" y1="52.07" x2="12.7" y2="52.07" width="0.1524" layer="91"/>
<wire x1="12.7" y1="52.07" x2="12.7" y2="50.8" width="0.1524" layer="91"/>
<label x="10.16" y="48.26" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SW3" gate="1" pin="S"/>
<wire x1="27.94" y1="116.84" x2="30.48" y2="116.84" width="0.1524" layer="91"/>
<wire x1="30.48" y1="116.84" x2="30.48" y2="114.3" width="0.1524" layer="91"/>
<pinref part="SW3" gate="1" pin="S1"/>
<wire x1="30.48" y1="114.3" x2="27.94" y2="114.3" width="0.1524" layer="91"/>
<wire x1="30.48" y1="114.3" x2="30.48" y2="106.68" width="0.1524" layer="91"/>
<junction x="30.48" y="114.3"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="LCA715" gate="G$1" pin="-CONTROL"/>
<wire x1="-121.92" y1="63.5" x2="-129.54" y2="63.5" width="0.1524" layer="91"/>
<label x="-137.16" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SERVO" gate="1" pin="4"/>
<wire x1="34.29" y1="27.94" x2="39.37" y2="27.94" width="0.1524" layer="91"/>
<label x="41.91" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-1" pin="S"/>
<wire x1="-111.76" y1="104.14" x2="-127" y2="104.14" width="0.1524" layer="91"/>
<label x="-132.08" y="106.68" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="POWER" gate="-1" pin="S"/>
<wire x1="50.8" y1="114.3" x2="48.26" y2="114.3" width="0.1524" layer="91"/>
<label x="43.18" y="114.3" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="POWER" gate="-2" pin="S"/>
<wire x1="50.8" y1="111.76" x2="48.26" y2="111.76" width="0.1524" layer="91"/>
<label x="40.64" y="111.76" size="1.778" layer="95"/>
</segment>
</net>
<net name="A4" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA4"/>
<wire x1="17.78" y1="69.85" x2="11.43" y2="69.85" width="0.1524" layer="91"/>
<label x="8.89" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SCREEN" gate="G$1" pin="5"/>
<wire x1="-16.51" y1="71.12" x2="-21.59" y2="71.12" width="0.1524" layer="91"/>
<label x="-24.13" y="71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="EN" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="EN"/>
<wire x1="60.96" y1="77.47" x2="64.77" y2="77.47" width="0.1524" layer="91"/>
<label x="68.58" y="77.47" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="POWER" gate="-3" pin="S"/>
<wire x1="50.8" y1="109.22" x2="48.26" y2="109.22" width="0.1524" layer="91"/>
<label x="43.18" y="109.22" size="1.778" layer="95"/>
</segment>
</net>
<net name="VBAT" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="VBAT"/>
<wire x1="60.96" y1="80.01" x2="66.04" y2="80.01" width="0.1524" layer="91"/>
<label x="67.31" y="80.01" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-2" pin="S"/>
<wire x1="-111.76" y1="101.6" x2="-127" y2="101.6" width="0.1524" layer="91"/>
<label x="-134.62" y="101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="3V" class="0">
<segment>
<pinref part="MOUSERAT" gate="1" pin="1"/>
<wire x1="58.42" y1="21.59" x2="62.23" y2="21.59" width="0.1524" layer="91"/>
<label x="64.77" y="20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SCREEN" gate="G$1" pin="8"/>
<wire x1="-16.51" y1="63.5" x2="-22.86" y2="63.5" width="0.1524" layer="91"/>
<label x="-25.4" y="62.23" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="OUTPUT" gate="A" pin="1"/>
<wire x1="-16.51" y1="36.83" x2="-24.13" y2="36.83" width="0.1524" layer="91"/>
<label x="-27.94" y="36.83" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="MS2" gate="G$1" pin="3V"/>
<wire x1="17.78" y1="87.63" x2="17.78" y2="86.36" width="0.1524" layer="91"/>
<wire x1="17.78" y1="86.36" x2="12.7" y2="86.36" width="0.1524" layer="91"/>
<label x="10.16" y="86.36" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LCA715" gate="G$1" pin="+LOAD"/>
<wire x1="-88.9" y1="71.12" x2="-76.2" y2="71.12" width="0.1524" layer="91"/>
<label x="-78.74" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LCA715" gate="G$1" pin="+LOAD2"/>
<wire x1="-88.9" y1="55.88" x2="-76.2" y2="55.88" width="0.1524" layer="91"/>
<label x="-78.74" y="55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="11" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO11"/>
<wire x1="60.96" y1="67.31" x2="64.77" y2="67.31" width="0.1524" layer="91"/>
<label x="64.77" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="MOUSERAT" gate="1" pin="3"/>
<wire x1="58.42" y1="26.67" x2="62.23" y2="26.67" width="0.1524" layer="91"/>
<label x="64.77" y="26.67" size="1.778" layer="95"/>
</segment>
</net>
<net name="12" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO12"/>
<wire x1="60.96" y1="69.85" x2="64.77" y2="69.85" width="0.1524" layer="91"/>
<label x="66.04" y="69.85" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="MOUSERAT" gate="1" pin="2"/>
<wire x1="58.42" y1="24.13" x2="62.23" y2="24.13" width="0.1524" layer="91"/>
<label x="64.77" y="22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="10" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO10"/>
<wire x1="60.96" y1="64.77" x2="64.77" y2="64.77" width="0.1524" layer="91"/>
<label x="68.58" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SERVO" gate="1" pin="2"/>
<wire x1="34.29" y1="22.86" x2="39.37" y2="22.86" width="0.1524" layer="91"/>
<label x="43.18" y="22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="A5" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA5"/>
<wire x1="17.78" y1="67.31" x2="13.97" y2="67.31" width="0.1524" layer="91"/>
<label x="10.16" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SW2" gate="1" pin="P1"/>
<wire x1="-15.24" y1="104.14" x2="-17.78" y2="104.14" width="0.1524" layer="91"/>
<pinref part="SW2" gate="1" pin="P"/>
<wire x1="-17.78" y1="104.14" x2="-22.86" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="106.68" x2="-17.78" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="106.68" x2="-17.78" y2="104.14" width="0.1524" layer="91"/>
<junction x="-17.78" y="104.14"/>
<label x="-22.86" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="5" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO5"/>
<wire x1="60.96" y1="57.15" x2="66.04" y2="57.15" width="0.1524" layer="91"/>
<label x="68.58" y="55.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SCREEN" gate="G$1" pin="6"/>
<wire x1="-16.51" y1="68.58" x2="-22.86" y2="68.58" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="68.58" x2="-24.13" y2="69.85" width="0.1524" layer="91"/>
<label x="-26.67" y="69.85" size="1.778" layer="95"/>
</segment>
</net>
<net name="6" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO6"/>
<wire x1="60.96" y1="59.69" x2="67.31" y2="59.69" width="0.1524" layer="91"/>
<label x="69.85" y="59.69" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SCREEN" gate="G$1" pin="4"/>
<wire x1="-16.51" y1="73.66" x2="-25.4" y2="73.66" width="0.1524" layer="91"/>
<label x="-26.67" y="74.93" size="1.778" layer="95"/>
</segment>
</net>
<net name="A0" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA0"/>
<wire x1="17.78" y1="80.01" x2="11.43" y2="80.01" width="0.1524" layer="91"/>
<label x="7.62" y="81.28" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="OUTPUT" gate="A" pin="5"/>
<wire x1="-16.51" y1="26.67" x2="-24.13" y2="26.67" width="0.1524" layer="91"/>
<label x="-29.21" y="26.67" size="1.778" layer="95"/>
</segment>
</net>
<net name="A1" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA1"/>
<wire x1="17.78" y1="77.47" x2="11.43" y2="77.47" width="0.1524" layer="91"/>
<label x="8.89" y="78.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="OUTPUT" gate="A" pin="4"/>
<wire x1="-16.51" y1="29.21" x2="-24.13" y2="29.21" width="0.1524" layer="91"/>
<wire x1="-24.13" y1="29.21" x2="-25.4" y2="27.94" width="0.1524" layer="91"/>
<label x="-26.67" y="29.21" size="1.778" layer="95"/>
</segment>
</net>
<net name="A2" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA2"/>
<wire x1="17.78" y1="74.93" x2="12.7" y2="74.93" width="0.1524" layer="91"/>
<label x="6.35" y="74.93" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="OUTPUT" gate="A" pin="3"/>
<wire x1="-16.51" y1="31.75" x2="-22.86" y2="31.75" width="0.1524" layer="91"/>
<label x="-25.4" y="31.75" size="1.778" layer="95"/>
</segment>
</net>
<net name="A3" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOA3"/>
<wire x1="17.78" y1="72.39" x2="13.97" y2="72.39" width="0.1524" layer="91"/>
<label x="11.43" y="72.39" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SW3" gate="1" pin="P1"/>
<wire x1="17.78" y1="114.3" x2="15.24" y2="114.3" width="0.1524" layer="91"/>
<pinref part="SW3" gate="1" pin="P"/>
<wire x1="15.24" y1="114.3" x2="10.16" y2="114.3" width="0.1524" layer="91"/>
<wire x1="17.78" y1="116.84" x2="15.24" y2="116.84" width="0.1524" layer="91"/>
<wire x1="15.24" y1="116.84" x2="15.24" y2="114.3" width="0.1524" layer="91"/>
<junction x="15.24" y="114.3"/>
<label x="10.16" y="114.3" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="13" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIO13"/>
<wire x1="60.96" y1="72.39" x2="64.77" y2="72.39" width="0.1524" layer="91"/>
<label x="68.58" y="72.39" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LCA715" gate="G$1" pin="+CONTROL"/>
<wire x1="-121.92" y1="71.12" x2="-129.54" y2="71.12" width="0.1524" layer="91"/>
<label x="-134.62" y="73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="TOUCH1" class="0">
<segment>
<pinref part="EXTRAGND" gate="G$1" pin="1"/>
<wire x1="12.7" y1="5.08" x2="22.86" y2="5.08" width="0.1524" layer="91"/>
<label x="17.78" y="2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="TOUCH_INPUT" gate="A" pin="3"/>
<wire x1="-41.91" y1="31.75" x2="-48.26" y2="31.75" width="0.1524" layer="91"/>
<label x="-50.8" y="31.75" size="1.778" layer="95"/>
</segment>
</net>
<net name="TOUCH2" class="0">
<segment>
<pinref part="EXTRAGND1" gate="G$1" pin="1"/>
<wire x1="12.7" y1="-2.54" x2="22.86" y2="-2.54" width="0.1524" layer="91"/>
<label x="17.78" y="-5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="TOUCH_INPUT" gate="A" pin="4"/>
<wire x1="-41.91" y1="29.21" x2="-49.53" y2="29.21" width="0.1524" layer="91"/>
<wire x1="-49.53" y1="29.21" x2="-50.8" y2="27.94" width="0.1524" layer="91"/>
<label x="-52.07" y="29.21" size="1.778" layer="95"/>
</segment>
</net>
<net name="TOUCH3" class="0">
<segment>
<pinref part="EXTRAGND2" gate="G$1" pin="1"/>
<wire x1="12.7" y1="-10.16" x2="22.86" y2="-10.16" width="0.1524" layer="91"/>
<label x="17.78" y="-12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="TOUCH_INPUT" gate="A" pin="5"/>
<wire x1="-41.91" y1="26.67" x2="-49.53" y2="26.67" width="0.1524" layer="91"/>
<label x="-55.88" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="1" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIOTX"/>
<wire x1="17.78" y1="54.61" x2="7.62" y2="54.61" width="0.1524" layer="91"/>
<wire x1="7.62" y1="54.61" x2="7.62" y2="53.34" width="0.1524" layer="91"/>
<label x="5.08" y="53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SW1" gate="1" pin="P1"/>
<wire x1="-60.96" y1="104.14" x2="-63.5" y2="104.14" width="0.1524" layer="91"/>
<pinref part="SW1" gate="1" pin="P"/>
<wire x1="-63.5" y1="104.14" x2="-68.58" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="106.68" x2="-63.5" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="106.68" x2="-63.5" y2="104.14" width="0.1524" layer="91"/>
<junction x="-63.5" y="104.14"/>
<label x="-68.58" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="0" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="GPIORX"/>
<wire x1="17.78" y1="57.15" x2="12.7" y2="57.15" width="0.1524" layer="91"/>
<wire x1="12.7" y1="57.15" x2="12.7" y2="58.42" width="0.1524" layer="91"/>
<label x="10.16" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="RESET" class="0">
<segment>
<pinref part="MS2" gate="G$1" pin="!RESET"/>
<wire x1="17.78" y1="90.17" x2="12.7" y2="90.17" width="0.1524" layer="91"/>
<wire x1="12.7" y1="90.17" x2="12.7" y2="88.9" width="0.1524" layer="91"/>
<label x="7.62" y="91.44" size="1.778" layer="95"/>
</segment>
</net>
<net name="SERVO_POWER" class="0">
<segment>
<pinref part="LCA715" gate="G$1" pin="-LOAD"/>
<wire x1="-88.9" y1="63.5" x2="-71.12" y2="63.5" width="0.1524" layer="91"/>
<label x="-83.82" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SERVO" gate="1" pin="3"/>
<wire x1="34.29" y1="25.4" x2="39.37" y2="25.4" width="0.1524" layer="91"/>
<label x="43.18" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
