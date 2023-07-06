using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Net;
using System.Threading.Tasks;


namespace Client.UI
{
	public class MainViewModel
	{
		public DataTable Table { get; }

		public string Text { get; private set; }
		
		//TODO(tsharpe): Resolve IP address to node name
		public List<string> Nodes { get; }

		public int SelectedIndex { get; set; }

		private TelemetryClient _client;

		public MainViewModel()
		{
			Table = new DataTable();
			Table.Columns.Add("Hash", typeof(UInt32));
			Table.Columns.Add("LastSeen", typeof(DateTime));
			Table.Columns.Add("Name", typeof(string));
			Table.Columns.Add("Type", typeof(string));
			Table.Columns.Add("Value", typeof(object));

			Text = string.Empty;

			Nodes = new List<string>();
			
			_client = new TelemetryClient();
		}

		public void Update()
		{
			Table.Rows.Clear();
			Nodes.Clear();

			if (_client.Nodes.Count == 0)
				return;

			//Update nodes
			foreach (IPAddress key in _client.Nodes.Keys)
			{
				Nodes.Add(key.ToString());
			}

			//Get selected node
			string selected = this.Nodes[SelectedIndex];
			IPAddress ip = IPAddress.Parse(selected);
			TelemetryClient.NodeTelem telem = _client.Nodes[ip];

			//Update devices
			foreach (var device in telem.Devices.Values)
			{
				Table.Rows.Add(device.Hash, device.LastSeen, device.Name, device.Type.ToString(), device.Value);
			}

			//Update text
			Text = string.Join("\n", telem.Text);
		}
	}
}