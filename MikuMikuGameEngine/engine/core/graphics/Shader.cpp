#include "stdafx.h"

#include "../util/util.h"

#include "Shader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Shader::Shader()
{
}

Shader::~Shader()
{
	Graphics::GetInstance()->DelResource( this );
}

bool Shader::CreateFromFile( const tstring& filePath )
{
	if( m_pEffect )
	{
		m_pEffect.Release();
		Graphics::GetInstance()->DelResource( this );
	}

	LPD3DXBUFFER pBuffer = NULL;

	HRESULT hr = D3DXCreateEffectFromFile( 
		Graphics::GetInstance()->GetDirect3DDevice(),
		filePath.c_str(),
		NULL,NULL,0,NULL,&m_pEffect,&pBuffer );

	if( pBuffer )
	{
		tstring error = to_tstring( (char*)pBuffer->GetBufferPointer() );
		OutputDebugStringFormat( _T("effect compiled\n%s"),error.c_str() );

		pBuffer->Release();
	}

	if( hr!=D3D_OK )
	{
		return false;
	}

	Graphics::GetInstance()->AddResource( this );

	return true;
}

bool Shader::CreateFromMemory( LPCVOID buffer,size_t size )
{
	Graphics* graphics = Graphics::GetInstance();

	if( m_pEffect )
	{
		m_pEffect.Release();
		graphics->DelResource( this );
	}

	LPD3DXBUFFER pBuffer = NULL;

	HRESULT hr = D3DXCreateEffect(
		graphics->GetDirect3DDevice(),
		buffer,
		size,
		NULL,NULL,0,NULL,&m_pEffect,&pBuffer );

	if( pBuffer )
	{
		tstring error = to_tstring( (char*)pBuffer->GetBufferPointer() );
		OutputDebugStringFormat( _T("effect compiled\n%s"),error.c_str() );

		pBuffer->Release();
	}

	if( hr!=D3D_OK )
	{
		return false;
	}

	graphics->AddResource( this );

	return true;
}

ID3DXEffectPtr Shader::GetEffect()
{
	return m_pEffect;
}

void Shader::OnLostDevice()
{
	OutputDebugStringFormat( _T("Shader(%p)::OnLostDevice\n"),this );

	if( m_pEffect )
	{
		m_pEffect->OnLostDevice();
	}
}

void Shader::OnResetDevice()
{
	OutputDebugStringFormat( _T("Shader(%p)::OnResetDevice\n"),this );

	if( m_pEffect )
	{
		m_pEffect->OnResetDevice();
	}
}