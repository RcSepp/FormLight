#ifdef _WIN32

#include <Windows.h>
#include <math.h>

class CManipulationEventSink : public _IManipulationEvents
{
	CManipulationEventSink(HWND hWnd, CDrawingObject *dObj, int iTimerId, BOOL inertia);
	HRESULT STDMETHODCALLTYPE ManipulationStarted(FLOAT x, FLOAT y);
};

CManipulationEventSink::CManipulationEventSink(HWND hWnd, CDrawingObject *dObj, int iTimerId, BOOL inertia) {
	// Manipulation & Inertia Processors
	m_manip = NULL;
	m_inert = NULL;

	// Connection points for COM.
	m_pConPointContainer = NULL;
	m_pConnPoint = NULL;

	// Reference to an object associated with this event sink.
	m_dObj = dObj;

	// Handle to the window used for computing boundaries.
	m_hWnd = hWnd;

	// The unique timer id for this manipulation event sink.
	m_iTimerId = iTimerId;

	m_bInertia = inertia;

	m_cRefCount = 1;
}


CManipulationEventSink::~CManipulationEventSink()
{

}


HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationStarted(
	FLOAT x,
	FLOAT y)
{

	KillTimer(m_hWnd, m_iTimerId);

	return S_OK;
}

HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationDelta(
	FLOAT x,
	FLOAT y,
	FLOAT translationDeltaX,
	FLOAT translationDeltaY,
	FLOAT scaleDelta,
	FLOAT expansionDelta,
	FLOAT rotationDelta,
	FLOAT cumulativeTranslationX,
	FLOAT cumulativeTranslationY,
	FLOAT cumulativeScale,
	FLOAT cumulativeExpansion,
	FLOAT cumulativeRotation)
{
	FLOAT pivot = 0.0f;

	// Apply transformation based on rotationDelta (in radians).
	FLOAT rads = 180.0f / 3.14159f;
	m_dObj->Rotate(rotationDelta*rads, x, y);

	// Apply translation based on scaleDelta.
	m_dObj->Scale(scaleDelta);

	// Apply translation based on translationDelta.
	m_dObj->Translate(translationDeltaX, translationDeltaY);

	if (!m_bInertia)
	{
		// Set values for one-finger rotations.
		FLOAT fPivotRadius = (FLOAT)(sqrt(pow(m_dObj->GetWidth() / 2, 2)
			+ pow(m_dObj->GetHeight() / 2, 2)))*0.4f;
		FLOAT fPivotPtX = m_dObj->GetCenterX();
		FLOAT fPivotPtY = m_dObj->GetCenterY();

		m_manip->put_PivotPointX(fPivotPtX);
		m_manip->put_PivotPointY(fPivotPtY);
		m_manip->put_PivotRadius(fPivotRadius);
	}
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationCompleted(
	FLOAT x,
	FLOAT y,
	FLOAT cumulativeTranslationX,
	FLOAT cumulativeTranslationY,
	FLOAT cumulativeScale,
	FLOAT cumulativeExpansion,
	FLOAT cumulativeRotation)
{
	if (!m_bInertia)
	{
		SetupInertia();

		// Kick off timer that handles inertia.
		SetTimer(m_hWnd, m_iTimerId, DESIRED_MILLISECONDS, NULL);
	}
	else
	{
		// Stop timer that handles inertia.
		KillTimer(m_hWnd, m_iTimerId);
	}

	return S_OK;
}

#endif