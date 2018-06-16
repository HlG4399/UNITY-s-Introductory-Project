using UnityEngine;
using System.Collections;

public class C_16_3_3_Client : MonoBehaviour
{
    void Start()
    {
        //指定MasterServer的IP地址
        MasterServer.ipAddress = "10.234.41.123";
        //指定MasterServer的端口号
        MasterServer.port = 23466;
        MasterServer.RequestHostList("CrazyBalls");
    }

    void OnGUI()
    {
        //得到所有服务器
        HostData[] data = MasterServer.PollHostList();
        //显示服务器列表，并可加入
        foreach (HostData hostData in data)
        {
            GUILayout.BeginHorizontal();
            string text = hostData.gameName + "房间人数：" + hostData.connectedPlayers + "/" + hostData.playerLimit;
            GUILayout.Label(text);
            string hostInfo = "";
            foreach (string hostIP in hostData.ip)
            {
                hostInfo += hostIP + ":";
            }
            hostInfo += hostData.port;
            if (GUILayout.Button("加入"))
            {
                Network.Connect(hostData);
            }
            GUILayout.EndHorizontal();
        }
    }
}
