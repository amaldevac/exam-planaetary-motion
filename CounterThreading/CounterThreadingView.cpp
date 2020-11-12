
// CounterThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CounterThreading.h"
#endif

#include "CounterThreadingDoc.h"
#include "CounterThreadingView.h"
#include "TestThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CCounterThreadingView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CCounterThreadingView::OnThreadPause)
	ON_COMMAND(ID_THREAD_RESUME, &CCounterThreadingView::OnThreadResume)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction

CCounterThreadingView::CCounterThreadingView()

{
	m_iCounter = 0;
	theta = 0, a = 244, b = 244,p=130,q=130;

	t = 3.14 / 180;
	x = 0, y = 0;
	x1 = 0, x2 = 0, x3 = 0, x4 = 0;
}

CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterThreadingView drawing

void CCounterThreadingView::OnDraw(CDC* pDC)
{

	CCounterThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//m_iCounter++;



	CPen redpen;
	redpen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* pOldpen = pDC->SelectObject(&redpen);
	//pDC->Ellipse(100, 120, 600, 600);
	pDC->Ellipse(110, 110, 600, 600);
	pDC->SelectObject(pOldpen);

	//outer orbit rotation

	for (int i = 0; i <= m_iCounter; i += 1)
	{
		theta = i;
		x = a * cos(t*theta);

		y = b * sin(t*theta);

	}
	for (int i = 0; i <= m_iCounter; i += 1)
	{
		CBrush brushblue(RGB(0, 0, 255));
		CBrush *pOldBrush = pDC->SelectObject(&brushblue);


		pDC->Ellipse(355 + x + 20, 350 + y + 20, 350 + x - 20, 350 + y - 20);

		Invalidate();
		pDC->SelectObject(pOldBrush);


	}
	CPen redpen1;
	redpen1.CreatePen(PS_SOLID, 5, RGB(0, 128, 0));
	CPen* pOldpen1 = pDC->SelectObject(&redpen1);
	//pDC->Ellipse(220, 200, 480, 500);
	pDC->Ellipse(220, 220, 480, 480);
	pDC->SelectObject(pOldpen1);


	//sun

	//CPen redpen2;
	CBrush brushred(RGB(0, 0, 0));
	CBrush *pOldbrush = pDC->SelectObject(&brushred);
	//redpen2.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	//CPen* pOldpen2 = pDC->SelectObject(&redpen2);
	pDC->Ellipse(305, 305, 400, 400);
	//pDC->SelectObject(pOldpen2);
	pDC->SelectObject(pOldbrush);


	//inner orbit rotation

	for (int i = 0; i <= m_iCounter; i += 1)
	{
		theta = i;
		x = p * cos(t*theta);

		y = q * sin(t*theta);

	}
	for (int i = 0; i <= m_iCounter; i += 1)
	{
		CBrush brushblue(RGB(255, 0, 0));
		CBrush *pOldBrush = pDC->SelectObject(&brushblue);


		pDC->Ellipse(350 + x + 20, 350 + y + 20, 350 + x - 20, 350 + y - 20);

		Invalidate();
		pDC->SelectObject(pOldBrush);


	}






}


/*CPen redpen;
redpen.CreatePen(PS_SOLID, 5, RGB(255, 0,0 ));
CPen* pOldpen = pDC->SelectObject(&redpen);
pDC->Ellipse(100, 120,600,600);
pDC->SelectObject(pOldpen);

CPen redpen1;
redpen1.CreatePen(PS_SOLID, 5, RGB(0, 128, 0));
CPen* pOldpen1 = pDC->SelectObject(&redpen1);
pDC->Ellipse(220, 200, 480, 500);
pDC->SelectObject(pOldpen1);

CPen redpen2;
CBrush brushred(RGB(0, 0, 0));
CBrush *pOldbrush = pDC->SelectObject(&brushred);
redpen2.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
CPen* pOldpen2= pDC->SelectObject(&redpen2);
pDC->Ellipse(305, 305, 400, 400);
pDC->SelectObject(pOldpen2);
pDC->SelectObject(pOldbrush);

//for (int i = 0; i <= m_iCounter; i++)
//{
//CPen redpen3;
//redpen3.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
//CPen* pOldpen3 = pDC->SelectObject(&redpen3);
CBrush brushred1(RGB(255, 0, 0));
CBrush *pOldbrush1 = pDC->SelectObject(&brushred1);
pDC->Ellipse(425 , 425 , 465 , 465);
//pDC->Ellipse(425+ m_iCounter, 425+ m_iCounter,465+ m_iCounter, 465+ m_iCounter);
//pDC->SelectObject(pOldpen3);
pDC->SelectObject(pOldbrush1);

//}
//for (int i = 0; i <= m_iCounter; i++)
//{
//CPen redpen4;
//redpen4.CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
//CPen* pOldpen4 = pDC->SelectObject(&redpen4);
CBrush brushred2(RGB(0, 0, 255));
CBrush *pOldbrush2 = pDC->SelectObject(&brushred2);
pDC->Ellipse(160 , 160 , 200 , 200 );
//pDC->Ellipse(160+ m_iCounter, 160+ m_iCounter, 200+ m_iCounter, 200+ m_iCounter);
//pDC->SelectObject(pOldpen4);
pDC->SelectObject(pOldbrush2);

//}*/












// CCounterThreadingView printing

BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterThreadingView message handlers


void CCounterThreadingView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);
}


void CCounterThreadingView::OnThreadPause()
{
	pThread->SuspendThread();
}


void CCounterThreadingView::OnThreadResume()
{
	pThread->ResumeThread();
}
