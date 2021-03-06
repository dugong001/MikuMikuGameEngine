
// MainFrm.h : CMainFrame クラスのインターフェイス
//

#pragma once
#include "ObjectListView.h"
#include "AssetExplorer.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"

class CMainFrame : public CFrameWndEx
{
	
protected: // シリアル化からのみ作成します。
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 実装
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバ
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	//CMFCToolBarImages m_UserImages;
	ObjectListView    m_wndObjectListView;
	CAssetExplorer     m_wndAssetExplorer;
	COutputWnd        m_wndOutput;
	CPropertiesWnd    m_wndProperties;

public:
	CAssetExplorer*    GetAssetExplorer(){ return &m_wndAssetExplorer; }
	ObjectListView*   GetObjectListView(){ return &m_wndObjectListView; }
	CPropertiesWnd*    GetPropertiesWnd(){ return &m_wndProperties; }

// 生成された、メッセージ割り当て関数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
};


