<TeXmacs|1.0.7.21>

<style|<tuple|book|style>>

<\body>
  <doc-data|<doc-title|Programming Practice
  Report>|<doc-author|<author-data|<author-name|<tabular|<tformat|<cwith|1|-1|1|1|cell-hyphen|n>|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|Subject>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|Phonebook>>>>|<row|<cell|Name>|<cell|>|<cell|<with|font|concrete|Weiju
  Lan> <with|font|fireflysung|(\<#5170\>\<#5A01\>\<#4E3E\>)>>>|<row|<cell|Major>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|Software
  Engineering>>>>|<row|<cell|Class>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|2013
  Class 1>>>>|<row|<cell|Id>|<cell|>|<cell|<with|font|concrete|<verbatim|13108115>>>>>>>>>>>

  <\table-of-contents|toc>
    <vspace*|1fn><with|font-series|bold|math-font-series|bold|1<space|2spc>Design>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-1><vspace|0.5fn>

    1.1<space|2spc>Goals <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-2>

    <with|par-left|1tab|1.1.1<space|2spc>The GUI
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-3>>

    <with|par-left|1tab|1.1.2<space|2spc>The Storage System
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-4>>

    1.2<space|2spc>User Interaction Diagram
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-5>

    <vspace*|1fn><with|font-series|bold|math-font-series|bold|2<space|2spc>Implementation>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-6><vspace|0.5fn>
  </table-of-contents>

  <chapter|Design>

  <section|Goals>

  The phonebook is designed to be a <term|GUI|Graphical User Interface>
  application for <verbatim|GNOME 3>. It's designed to be <emp|modern>,
  <emp|safe> and <emp|linux-only>. The whole project is written in
  <verbatim|GNU C++ 14>.

  The phonebook should store the contact's name and phone number. The user
  should be able to add a new contact, edit or remove an existing contact,
  and search the phonebook for contacts by name or by phone. The saving
  process should be transparent to the user, so that the user need not to
  worry about saving.\ 

  <subsection|The GUI>

  The GUI should be <emp|modern> and straightforward like any other
  <verbatim|GNOME 3> applications. It should have only 1 window displaying
  the data (in this case, the contact list) with most of the actions on the
  titlebar.

  <subsection|The Storage System>

  The data should be stored using <term|NDE|Non-Destructive Editing>
  strategy.

  In this way, we should only save the operations/actions on the data instead
  of the data itself. Thus the whole editing history is saved, so the user is
  able to undo/redo even after closing and reopening the application. Because
  only the actions are saved, we can do this <em|on the fly> so the user
  don't need to click ``save'' all the time, making the saving process
  <em|transparent> and <emp|safe> (the old actions won't be missing because
  we only append new actions to the end of file).

  All the actions should be saved in <em|plain text>, each action in one
  line, so that once saving failure happens, the user can recover easily by
  removing the last line.

  But, huge editing history may cause the application to load slowly and eat
  lots of memory. So another mechanism is provided: <em|snapshot>.

  Snapshotting should remove all the actions and save the data (instead of
  actions) in a compressed compact binary format. It should first save to a
  temporary file, then rename to the original file to avoid saving failure.

  After snapshotting, the editing history will be <em|lost>. Thus the user
  cannot undo the actions that happened before snapshotting.

  <section|User Interaction Diagram>

  The UX.

  <chapter|Implementation>
</body>

<\initial>
  <\collection>
    <associate|font|roman>
    <associate|math-font|roman>
    <associate|page-medium|paper>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|5>>
    <associate|auto-2|<tuple|1.1|5>>
    <associate|auto-3|<tuple|1.1.1|5>>
    <associate|auto-4|<tuple|1.1.2|5>>
    <associate|auto-5|<tuple|1.2|5>>
    <associate|auto-6|<tuple|2|7>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>Design>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>

      1.1<space|2spc>Goals <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2>

      <with|par-left|<quote|1tab>|1.1.1<space|2spc>The GUI
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3>>

      <with|par-left|<quote|1tab>|1.1.2<space|2spc>The Storage System
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-4>>

      1.2<space|2spc>User Interaction Diagram
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-5>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|2<space|2spc>Implementation>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-6><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>