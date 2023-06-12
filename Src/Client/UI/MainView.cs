using Terminal.Gui;
using System.Data;

namespace Client.UI
{
	public class MainView : Toplevel
	{
		private const int UpdateInterval = 1000;
		
		// Top level controls
		private MenuBar _menuBar;
		private FrameView _listFrame;
		private FrameView _selectedFrame;
		private StatusBar _statusBar;

		// Clients list frame controls
		private ListView _nodesListView;

		// Selected client frame controls
		private TabView _tabView;
		private TableView _tableView;
		private TextView _textView;

		private MainViewModel _model;

		//Update control
		private Timer _timer;

		public MainView()
		{
			ColorScheme = Colors.Base;

			_menuBar = new MenuBar(
				new MenuBarItem[]
				{
					new MenuBarItem("_File", new MenuItem[] { new MenuItem ("_Quit", "Quit Client", () => RequestStop(), null, null, Key.Q | Key.CtrlMask)}),
				});
			this.Add(_menuBar);

			_listFrame = new FrameView ("Nodes")
			{
					X = 0,
					Y = 1, // for menu
					Width = 25,
					Height = Dim.Fill(1),
					CanFocus = true,
					Shortcut = Key.CtrlMask | Key.CursorLeft
			};
			_listFrame.Title = $"{_listFrame.Title} ({_listFrame.ShortcutTag})";
			_listFrame.ShortcutAction = () => _listFrame.SetFocus ();
			this.Add(_listFrame);

			_selectedFrame = new FrameView ("Selected Node")
			{
				X = 25,
				Y = 1, // for menu
				Width = Dim.Fill (),
				Height = Dim.Fill (1),
				CanFocus = true,
				Shortcut = Key.CtrlMask | Key.CursorRight
			};
			_selectedFrame.Title = $"{_selectedFrame.Title} ({_selectedFrame.ShortcutTag})";
			_selectedFrame.ShortcutAction = () => _selectedFrame.SetFocus ();
			this.Add(_selectedFrame);

			_statusBar = new StatusBar()
			{
				Visible = true,
				Items = new StatusItem[]
				{
					new StatusItem(Key.Q | Key.CtrlMask, "~CTRL-Q~ Quit", () => {
						RequestStop();
					}),
				}
			};
			this.Add(_statusBar);

			_nodesListView = new ListView ()
			{
				X = 0,
				Y = 0,
				Width = Dim.Fill (0),
				Height = Dim.Fill (0),
				CanFocus = true,
			};
			_nodesListView.OpenSelectedItem += (a) =>
			{
				_selectedFrame.SetFocus ();
			};
			_nodesListView.SelectedItemChanged += (e) =>
			{
				_model.SelectedIndex = e.Item;
			};
			_listFrame.Add(_nodesListView);

			_tabView = new TabView()
			{
				X = 0,
				Y = 0,
				Width = Dim.Fill(),
				Height = Dim.Fill(),
			};
			_selectedFrame.Add(_tabView);

			_tableView = new TableView()
			{
				X = 0,
				Y = 0,
				Width = Dim.Fill(),
				Height = Dim.Fill(),
			};
			_tabView.AddTab(new TabView.Tab("Devices", _tableView), false);

			_textView = new TextView()
			{
				X = 0,
				Y = 0,
				Width = Dim.Fill(),
				Height = Dim.Fill(),
				ReadOnly = true,
			};
			_tabView.AddTab(new TabView.Tab("Text", _textView), false);

			_timer = new Timer(
				(o) =>
				{
					Application.MainLoop?.Invoke (() => UpdateUI());
				}, null, 0, UpdateInterval);

			_model = new MainViewModel();
		}

		private void UpdateUI()
		{
			_model.Update();
			_nodesListView.SetSource(_model.Nodes);
			_tableView.Table = _model.Table;
			_textView.Text = _model.Text;
		}
	}
}
