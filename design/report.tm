<TeXmacs|1.0.7.21>

<style|<tuple|book|style>>

<\body>
  <doc-data|<doc-title|Programming Practice Report>|<doc-subtitle|of Software
  Engineering School>|<doc-author|<author-data|<author-name|<tabular|<tformat|<cwith|1|-1|1|1|cell-hyphen|n>|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|Subject>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|Phonebook>>>>|<row|<cell|Author>|<cell|>|<cell|<with|font|concrete|Weiju
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

    2.1<space|2spc>Overview <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-7>

    2.2<space|2spc>Phonebook <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-11>

    <with|par-left|1tab|2.2.1<space|2spc><with|font-family|tt|language|verbatim|main>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-12>>

    2.3<space|2spc>The GUI <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-13>

    <with|par-left|1tab|2.3.1<space|2spc><with|font-family|tt|language|verbatim|main_window>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-14>>

    <with|par-left|1tab|2.3.2<space|2spc><with|font-family|tt|language|verbatim|contact_input_bar>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-15>>

    <with|par-left|1tab|2.3.3<space|2spc><with|font-family|tt|language|verbatim|info_entry>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-16>>

    <with|par-left|1tab|2.3.4<space|2spc><with|font-family|tt|language|verbatim|contact_search_bar>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-17>>

    <with|par-left|1tab|2.3.5<space|2spc><with|font-family|tt|language|verbatim|contact_list>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-18>>

    <with|par-left|1tab|2.3.6<space|2spc><with|font-family|tt|language|verbatim|contact>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-19>>

    2.4<space|2spc>The NDE <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-20>

    <with|par-left|1tab|2.4.1<space|2spc><with|font-family|tt|language|verbatim|path>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-21>>

    <with|par-left|1tab|2.4.2<space|2spc><with|font-family|tt|language|verbatim|factory>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-22>>

    <with|par-left|1tab|2.4.3<space|2spc><with|font-family|tt|language|verbatim|project/type>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-23>>

    <with|par-left|1tab|2.4.4<space|2spc><with|font-family|tt|language|verbatim|project/instance>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-24>>

    <with|par-left|1tab|2.4.5<space|2spc><with|font-family|tt|language|verbatim|project/data>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-25>>

    <with|par-left|1tab|2.4.6<space|2spc><with|font-family|tt|language|verbatim|project/file>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-26>>

    <with|par-left|1tab|2.4.7<space|2spc><with|font-family|tt|language|verbatim|project/snapshot>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-27>>

    <with|par-left|1tab|2.4.8<space|2spc><with|font-family|tt|language|verbatim|action/type>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-28>>

    <with|par-left|1tab|2.4.9<space|2spc><with|font-family|tt|language|verbatim|action/helper>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-29>>

    <with|par-left|1tab|2.4.10<space|2spc><with|font-family|tt|language|verbatim|action/wrapper>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-30>>

    <with|par-left|1tab|2.4.11<space|2spc><with|font-family|tt|language|verbatim|undo>,
    <with|font-family|tt|language|verbatim|redo>,
    <with|font-family|tt|language|verbatim|create>,
    <with|font-family|tt|language|verbatim|remove> and
    <with|font-family|tt|language|verbatim|edit> in
    <with|font-family|tt|language|verbatim|action>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-31>>

    <vspace*|1fn><with|font-series|bold|math-font-series|bold|3<space|2spc>Summary
    and Thoughts> <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-32><vspace|0.5fn>
  </table-of-contents>

  <chapter|Design>

  <section|Goals>

  The phonebook is designed to be a <term|GUI|Graphical User Interface>
  application for <verbatim|GNOME 3>. It's designed to be <emp|modern>,
  <emp|safe> and <emp|linux-only>. The whole project is written in
  <verbatim|GNU C++14>.

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

  See <emp|Appendix A> for details.

  <chapter|Implementation>

  <section|Overview>

  <\itemize>
    <item>The whole project uses <verbatim|git> to do the version control

    <item>The building system uses a custom one of mine, which includes a
    <verbatim|perl>-written <verbatim|configure> script that generates
    <verbatim|GNU makefile>. Then the actual building is coordinated by
    <verbatim|GNU make>, which calls <verbatim|g++> to build the whole
    application.

    <item>The application is written in <verbatim|GNU C++14>, use
    <verbatim|gtkmm 3> for GUI and <verbatim|zlib> for compression.

    <item>Designed with <verbatim|C++>'s multi-paradigm in mind. Used
    <term|OOP|Object-Oriented Programming>, <term|FP|Functional Programming>,
    <term|GP|Generic Programming> and <term|MP|Meta-Programming> techniques.
  </itemize>

  \;

  <\big-figure>
    <tree|<verbatim|/>|<verbatim|design>|<tree|<verbatim|src>|<verbatim|ui>|<tree|<verbatim|nde>|<verbatim|action>|<verbatim|project>>>|<verbatim|res>>
  </big-figure|Source tree.>

  \;

  <big-table|<tabular|<tformat|<table|<row|<cell|<verbatim|/design>>|<cell|>|<cell|the
  design drafts and documentations>>|<row|<cell|<verbatim|/res>>|<cell|>|<cell|the
  resources: a <verbatim|desktop> file and some experimenting contacts
  data>>|<row|<cell|<verbatim|/src>>|<cell|>|<cell|all the source
  code>>|<row|<cell|<verbatim|/src/ui>>|<cell|>|<cell|the user interface and
  interaction code>>|<row|<cell|<verbatim|/src/nde>>|<cell|>|<cell|the
  non-destructive editing engine>>|<row|<cell|<verbatim|/src/nde/action>>|<cell|>|<cell|all
  the actions>>|<row|<cell|<verbatim|/src/nde/project>>|<cell|>|<cell|an nde
  project (a manager of actions and file operations)>>>>>|Directories>

  \;

  \;

  <big-figure|<verbatim|<tabular|<tformat|<table|<row|<cell|phonebook>|<cell|>|<cell|>|<cell|>>|<row|<cell|\|-------->|<cell|main>|<cell|>|<cell|>>|<row|<cell|\|-------->|<cell|ui>|<cell|>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|main_window>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|contact_input_bar>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|contact_search_bar>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|contact_list>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|info_entry>|<cell|>>|<row|<cell|\|>|<cell|\|--->|<cell|contact>|<cell|>>|<row|<cell|\|-------->|<cell|nde>|<cell|>|<cell|>>|<row|<cell|>|<cell|\|--->|<cell|init>|<cell|>>|<row|<cell|>|<cell|\|--->|<cell|path>|<cell|>>|<row|<cell|>|<cell|\|--->|<cell|factory>|<cell|>>|<row|<cell|>|<cell|\|--->|<cell|project>|<cell|>>|<row|<cell|>|<cell|\|>|<cell|\|----------------->|<cell|type>>|<row|<cell|>|<cell|\|>|<cell|\|----------------->|<cell|instance>>|<row|<cell|>|<cell|\|>|<cell|\|----------------->|<cell|data>>|<row|<cell|>|<cell|\|>|<cell|\|----------------->|<cell|file>>|<row|<cell|>|<cell|\|>|<cell|\|----------------->|<cell|snapshot>>|<row|<cell|>|<cell|\|--->|<cell|action>|<cell|>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|type>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|helper>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|wrapper>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|undo>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|redo>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|create>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|remove>>|<row|<cell|>|<cell|>|<cell|\|----------------->|<cell|edit>>>>>>|Components>

  <section|Phonebook>

  <subsection|<verbatim|main>>

  The <verbatim|main> function creates a new <verbatim|gtk3>
  <verbatim|Application> and a new <verbatim|MainWindow>, then run the
  application with the new window.

  <section|The GUI>

  <subsection|<verbatim|main_window>>

  The <verbatim|MainWindow> class creates the main window, populate the
  titlebar with a <verbatim|HeaderBar> with <verbatim|Button>s on it, create
  <verbatim|ContactInputBar> and <verbatim|ContactSearchBar>, populate the
  window content with <verbatim|ContactList> and connect various
  <verbatim|signal>s to provide user interactions.

  Some <verbatim|Button>s on the <verbatim|HeaderBar> will call
  <verbatim|nde::action::<math|\<cdots\>\<cdots\>>> to perform the action.

  <subsection|<verbatim|contact_input_bar>>\ 

  When adding or editing a contact, the <verbatim|ContactInputBar> will be
  shown to ask the user to input the contact information (i.e. contact's name
  and phone number).

  When the user confirmed his input, the <verbatim|ContactInputBar> will ask
  its <verbatim|InfoEntry>s to validate the inpur. The validating method is
  passed to the <verbatim|InfoEntry>s when constructing by using
  <verbatim|lambda functions> of <verbatim|C++14>.

  <subsection|<verbatim|info_entry>>

  <verbatim|InfoEntry> is a subclass of <verbatim|gtk3>'s <verbatim|Entry> to
  provide <em|input-validation> functionality. The validating function
  <verbatim|Validator> is passed to the <verbatim|InfoEntry> as a
  <verbatim|functor>. The validation will be performed on the fly when the
  user is inputing. The validation can also be asked explicitly to force the
  validation and get the result.

  <subsection|<verbatim|contact_search_bar>>

  <verbatim|ContactSearchBar> is a subclass of <verbatim|gtk3>'s
  <verbatim|SearchBar> to wrap the <verbatim|gtk3>'s <verbatim|SearchEntry>
  inside, making the code easier to write.

  <subsection|<verbatim|contact_list>>

  <verbatim|ContactList> is used to show all the <verbatim|Contact>s. When
  constructing, it will connect the <verbatim|nde>'s callbacks by using
  <verbatim|lambda function>.

  <subsection|<verbatim|contact>>

  <verbatim|Contact> displays one contact's information using
  <verbatim|Label>s with <verbatim|markup> for formatting. The layout is
  constructed by various <verbatim|box>es. It also contains a
  <verbatim|ContactInputBar> for editing the contact. It will call
  <verbatim|nde::action::<math|\<cdots\>\<cdots\>>> to perform editing and
  removing.

  <section|The NDE>

  The NDE is a hand-crafted non-destructive editing engine. Normally, it
  stores actions, but when asked to snapshot, it will store data and remove
  all the actions.

  <subsection|<verbatim|path>>

  This <verbatim|namespace> is used for getting various file paths like the
  project's path or the snapshot's path.

  <subsection|<verbatim|factory>>

  Template class <verbatim|Factory\<less\>Base\<gtr\>> is used to create a
  factory, which creates objects of the subclasses of <verbatim|Base> by
  their names.

  Proxy template class <verbatim|Maker\<less\>T\<gtr\>> (where <verbatim|T>
  is a subclass of <verbatim|Base>) is used to register a subclass into the
  factory.

  For instructions on how to use these, see the source code
  <verbatim|/src/nde/factory.hh>.

  <subsection|<verbatim|project/type>>

  <verbatim|project::Type> is a manager that manages actions, data and files.

  <subsection|<verbatim|project/instance>>

  <verbatim|project::instance()> is used as a singleton. It returns a single
  instance of <verbatim|project::Type>.

  <subsection|<verbatim|project/data>>

  <verbatim|project::Data> stores the contact data: name and phone number.

  <subsection|<verbatim|project/file>>

  <verbatim|project::File> is used for serialization of actions. It provides
  interface to read/write escaped quoted string (by using
  <verbatim|std::quotes> in <verbatim|\<less\>iomanip\<gtr\>> of
  <verbatim|C++14>), integers, atoms and end of lines.

  <subsection|<verbatim|project/snapshot>>

  This <verbatim|namespace> is used for reading/writing snapshot files. A
  snapshot file is a <verbatim|gzip>-compressed compact binary data.

  <subsection|<verbatim|action/type>>

  <verbatim|action::Type> is the <em|abstract> base class of actions.

  It also contains the factory of <verbatim|action::Type>.

  <subsection|<verbatim|action/helper>>

  This <verbatim|namespace> is used for helping the reading/writing of
  actions.

  <subsection|<verbatim|action/wrapper>>

  The template class <verbatim|action::Wrapper\<less\>Action\<gtr\>> is used
  to wrap a subclass of <verbatim|action::Type>, making it registered to the
  <verbatim|action::factory>. The internal can also easierly construct the
  action by just calling the wrapped object (<verbatim|functor>, it
  implements <verbatim|operator()(...)>).

  <subsection|<verbatim|undo>, <verbatim|redo>, <verbatim|create>,
  <verbatim|remove> and <verbatim|edit> in <verbatim|action>>

  They are the concrete actions derived from <verbatim|action::Type>.

  Taking <verbatim|create> for example. It implements reading/writing using
  <verbatim|project::File>. Two callbacks exist as static member variables.
  They are <verbatim|invoke_cb> and <verbatim|undo_cb> implemented by using
  <verbatim|std::function> of <verbatim|C++14>. Callbacks will be called when
  corresponding operations happened. It also uses the wrapper by
  <verbatim|Wrapper\<less\>Create\<gtr\> create{"create"}>.

  <verbatim|undo> and <verbatim|redo> have no callback.

  <chapter|Summary and Thoughts>

  Even a small phonebook application is complex, especially when you want it
  to be <emp|mature>.

  I've heard of non-destructive editing long time ago, but this is the first
  time I've tried to implement one. Some dirty hacks exist though, but the
  code is clean in general. This is also a chance for me to learn
  <verbatim|gtkmm 3>.

  Applying various techniques from different paradigms is really important to
  write <em|clean>, <em|simple> and <em|readable> code in <verbatim|C++>.
  Hand-crafting the GUI is so complex. I would use a GUI design tool next
  time.

  <verbatim|C++14> rocks. I hope <verbatim|clang> will support it soon. The
  debugging information from <verbatim|clang> is much better than that from
  <verbatim|GCC>.

  \;

  \;

  \;

  \;

  \;

  <\right-aligned>
    <tabular|<tformat|<cwith|1|1|1|1|cell-halign|c>|<table|<row|<cell|<with|font-base-size|12|<with|font|concrete|Software
    Enginnering School>>>>|<row|<cell|>>|<row|<cell|<tabular|<tformat|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|<name|Class>>|<cell|>|<cell|<with|font|concrete|2013
    Class 1>>>|<row|<cell|<name|Author>>|<cell|>|<cell|<name|<with|font|concrete|Weiju
    Lan>> <with|font|fireflysung|(\<#5170\>\<#5A01\>\<#4E3E\>)>>>|<row|<cell|<name|Id>>|<cell|>|<cell|<with|font|concrete|<verbatim|13108115>>>>|<row|<cell|<name|Date>>|<cell|>|<cell|<verbatim|<with|font|concrete|2014/06/25>>>>>>>>>>>><space|2tab>
  </right-aligned>
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
    <associate|auto-10|<tuple|2.2|8>>
    <associate|auto-11|<tuple|2.2|8>>
    <associate|auto-12|<tuple|2.2.1|8>>
    <associate|auto-13|<tuple|2.3|8>>
    <associate|auto-14|<tuple|2.3.1|8>>
    <associate|auto-15|<tuple|2.3.2|8>>
    <associate|auto-16|<tuple|2.3.3|9>>
    <associate|auto-17|<tuple|2.3.4|9>>
    <associate|auto-18|<tuple|2.3.5|9>>
    <associate|auto-19|<tuple|2.3.6|9>>
    <associate|auto-2|<tuple|1.1|5>>
    <associate|auto-20|<tuple|2.4|9>>
    <associate|auto-21|<tuple|2.4.1|9>>
    <associate|auto-22|<tuple|2.4.2|9>>
    <associate|auto-23|<tuple|2.4.3|9>>
    <associate|auto-24|<tuple|2.4.4|10>>
    <associate|auto-25|<tuple|2.4.5|10>>
    <associate|auto-26|<tuple|2.4.6|10>>
    <associate|auto-27|<tuple|2.4.7|10>>
    <associate|auto-28|<tuple|2.4.8|10>>
    <associate|auto-29|<tuple|2.4.9|10>>
    <associate|auto-3|<tuple|1.1.1|5>>
    <associate|auto-30|<tuple|2.4.10|10>>
    <associate|auto-31|<tuple|2.4.11|10>>
    <associate|auto-32|<tuple|3|11>>
    <associate|auto-4|<tuple|1.1.2|5>>
    <associate|auto-5|<tuple|1.2|5>>
    <associate|auto-6|<tuple|2|7>>
    <associate|auto-7|<tuple|2.1|7>>
    <associate|auto-8|<tuple|2.1|7>>
    <associate|auto-9|<tuple|2.1|7>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|figure>
      <tuple|normal|Source tree.|<pageref|auto-8>>

      <tuple|normal|Components|<pageref|auto-10>>
    </associate>
    <\associate|table>
      <tuple|normal|Directories|<pageref|auto-9>>
    </associate>
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

      2.1<space|2spc>Overview <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-7>

      2.2<space|2spc>Phonebook <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-11>

      <with|par-left|<quote|1tab>|2.2.1<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|main>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-12>>

      2.3<space|2spc>The GUI <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-13>

      <with|par-left|<quote|1tab>|2.3.1<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|main_window>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-14>>

      <with|par-left|<quote|1tab>|2.3.2<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|contact_input_bar>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-15>>

      <with|par-left|<quote|1tab>|2.3.3<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|info_entry>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-16>>

      <with|par-left|<quote|1tab>|2.3.4<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|contact_search_bar>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-17>>

      <with|par-left|<quote|1tab>|2.3.5<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|contact_list>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-18>>

      <with|par-left|<quote|1tab>|2.3.6<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|contact>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-19>>

      2.4<space|2spc>The NDE <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-20>

      <with|par-left|<quote|1tab>|2.4.1<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|path>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-21>>

      <with|par-left|<quote|1tab>|2.4.2<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|factory>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-22>>

      <with|par-left|<quote|1tab>|2.4.3<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|project/type>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-23>>

      <with|par-left|<quote|1tab>|2.4.4<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|project/instance>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-24>>

      <with|par-left|<quote|1tab>|2.4.5<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|project/data>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-25>>

      <with|par-left|<quote|1tab>|2.4.6<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|project/file>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-26>>

      <with|par-left|<quote|1tab>|2.4.7<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|project/snapshot>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-27>>

      <with|par-left|<quote|1tab>|2.4.8<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|action/type>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-28>>

      <with|par-left|<quote|1tab>|2.4.9<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|action/helper>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-29>>

      <with|par-left|<quote|1tab>|2.4.10<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|action/wrapper>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-30>>

      <with|par-left|<quote|1tab>|2.4.11<space|2spc><with|font-family|<quote|tt>|language|<quote|verbatim>|undo>,
      <with|font-family|<quote|tt>|language|<quote|verbatim>|redo>,
      <with|font-family|<quote|tt>|language|<quote|verbatim>|create>,
      <with|font-family|<quote|tt>|language|<quote|verbatim>|remove> and
      <with|font-family|<quote|tt>|language|<quote|verbatim>|edit> in
      <with|font-family|<quote|tt>|language|<quote|verbatim>|action>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-31>>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|3<space|2spc>Summary
      and Thoughts> <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-32><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>